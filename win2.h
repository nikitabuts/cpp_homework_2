#ifndef WIN2_H
#define WIN2_H
#include "domitem.h"
#include <QDomElement>
#include <QMainWindow>

namespace Ui {
class Win2;
}

class Win2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit Win2(QWidget *parent = nullptr);
    ~Win2();

    void sendItem(const DomItem *item);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::Win2 *ui;
    const DomItem *el;
    QDomElement it;
};

#endif // WIN2_H
