#include "dommodel.h"
#include "domitem.h"

#include <QtXml>

DomModel::DomModel(const QDomDocument &document, QObject *parent)
    : QAbstractItemModel(parent),
      domDocument(document),
      rootItem(new DomItem(domDocument, 0))
{
}
//! [0]
DomModel::~DomModel()
{
    delete rootItem;
}
//! [1]

//! [2]
int DomModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 1;//3
}

QDomDocument *DomModel::getModel()
{
    return &domDocument;
}
//! [2]

//! [3]
QVariant DomModel::data(const QModelIndex &index, int role) const // Выдача данных с параметрами по роли и индексу
{
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    const DomItem *item = static_cast<DomItem*>(index.internalPointer());

    const QDomNode node = item->node();
//! [3] //! [4]

    switch (index.column()) {   // итерируемся по количеству колонок и выдаём значение в зависимости от значений

        case 0:
        {
            const QDomNamedNodeMap attributeMap = node.attributes();

            return attributeMap.namedItem("name").nodeValue();

        }

    }
    return QVariant();
}
//! [4]

//! [5]
Qt::ItemFlags DomModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index);
}
//! [5]

//! [6]
QVariant DomModel::headerData(int section, Qt::Orientation orientation,
                              int role) const   // загловки таблицы
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
            case 0:
                return tr("");
//            case 1:
//                return tr("Attributes");
//            case 2:
//                return tr("Value");
            default:
                break;
        }
    }
    return QVariant();
}
//! [6]

//! [7]
QModelIndex DomModel::index(int row, int column, const QModelIndex &parent) const // выдача индекса
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    DomItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<DomItem*>(parent.internalPointer());
//! [7]

//! [8]
    DomItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}
//! [8]

//! [9]
QModelIndex DomModel::parent(const QModelIndex &child) const
{
    if (!child.isValid())
        return QModelIndex();

    DomItem *childItem = static_cast<DomItem*>(child.internalPointer());
    DomItem *parentItem = childItem->parent();

    if (!parentItem || parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}
//! [9]

//! [10]
int DomModel::rowCount(const QModelIndex &parent) const // подсчёт строк
{
    if (parent.column() > 0)
        return 0;

    DomItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<DomItem*>(parent.internalPointer());

    return parentItem->node().childNodes().count();
}
//! [10]
