#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QFile>
#include "dommodel.h"
#include "domitem.h"
#include <QTextStream>

// ui для главного окна

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(new DomModel(QDomDocument(), this))
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked() // открытие файла
{
    filePath = QFileDialog::getOpenFileName(this, tr("Open File"),
        xmlPath, tr("XML files (*.xml);;HTML files (*.html);;"
                    "SVG files (*.svg);;User Interface files (*.ui)"));

    if (!filePath.isEmpty()) {

        QFile file(filePath);

        if (file.open(QIODevice::ReadOnly)) {

            QDomDocument document;
            if (document.setContent(&file)) {

                model = new DomModel(document, this); // инициализируем модель для XML
                ui->treeView->setModel(model); // назначает модели view древовидную структуру
                xmlPath = filePath;

            }
            file.close();
        }
    }


    ui->treeView->setModel(model);
}

void MainWindow::on_pushButton_2_clicked() // save
{
    QFile file(filePath);
    file.open(QIODevice::ReadWrite);
    QTextStream st(&file);
    model->getModel()->save(st, 4); // сохраняем изменения в модели в файл
    file.close();
}

void MainWindow::on_treeView_doubleClicked(const QModelIndex &index) //edit in new window
{
    const DomItem *item = static_cast<DomItem*>(index.internalPointer());
    const QDomNode node = item->node();
    if (node.isElement()){
        if (!node.hasChildNodes()){
            QDomElement m = node.toElement();
            if (m.tagName() == "album"){
                win.sendItem(item);
                win.show();
            }
        }
    }
}
