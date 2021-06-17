#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeView>
#include <QDomDocument>
#include <QDomNode>
#include <QHash>
#include "dommodel.h"
#include "win2.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
class QTreeView;
class QMenu;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_treeView_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    DomModel *model;
    QMenu *fileMenu;
    QString xmlPath;
    QString filePath;
    Win2 win;
};
#endif // MAINWINDOW_H
