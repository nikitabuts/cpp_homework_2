#include "domitem.h"

#include <QtXml>

//
// Написание модели класс QDomDocument по стандарту QAbstractItemModel
//

DomItem::DomItem(const QDomNode &node, int row, DomItem *parent) // инициализируем класс с наследованеием
    : domNode(node),
      parentItem(parent),
      rowNumber(row)
{}

DomItem::~DomItem() // деструктор
{
    qDeleteAll(childItems);
}

QDomNode DomItem::node() const // получение указателя на ноду
{
    return domNode;
}

DomItem *DomItem::parent() // получение на родителя
{
    return parentItem;
}

DomItem *DomItem::child(int i) // получение указаталея на потомка
{
    DomItem *childItem = childItems.value(i);
    if (childItem)
        return childItem;

    if (i >= 0 && i < domNode.childNodes().count()) {
        QDomNode childNode = domNode.childNodes().item(i);
        childItem = new DomItem(childNode, i, this);
        childItems[i] = childItem;
    }
    return childItem;
}

int DomItem::row() const
{
    return rowNumber;
}
