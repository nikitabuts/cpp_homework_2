#include "win2.h"
#include "ui_win2.h"

// класс окна на изменение

Win2::Win2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Win2)
{
    ui->setupUi(this);
}

Win2::~Win2()
{
    delete ui;
}

void Win2::sendItem(const DomItem *item)
{
    el = item;

    const QDomNode node = el->node();
    it = node.toElement();

    // инициализурем все поля

    ui->auth_lineEdit->setText(it.attribute("group_name"));
    ui->title_lineEdit->setText(it.attribute("name"));
    ui->dateEdit->setDate(QDate::fromString(it.attribute("date"), "yyyy-MM-dd"));
    ui->descr_textEdit->setText(it.attribute("desc"));
    ui->minut_spinBox->setValue(it.attribute("minut").toInt());
    ui->second_spinBox_2->setValue(it.attribute("second").toInt());
    ui->studio_lineEdit->setText(it.attribute("studio"));
    ui->label_lineEdit->setText(it.attribute("label"));
}

void Win2::on_pushButton_clicked() //сохраняем изменения в полях
{
    it.setAttribute("name", ui->title_lineEdit->text());
    it.setAttribute("label", ui->label_lineEdit->text());
    it.setAttribute("studio", ui->studio_lineEdit->text());
    it.setAttribute("group_name", ui->auth_lineEdit->text());
    it.setAttribute("date", ui->dateEdit->date().toString("yyyy-MM-d"));
    it.setAttribute("desc", ui->descr_textEdit->toPlainText());
    it.setAttribute("minut",QString::number(ui->minut_spinBox->value()));
    it.setAttribute("second", QString::number(ui->second_spinBox_2->value()));

    this->close();
}

void Win2::on_pushButton_2_clicked() //close
{
    this->close();
}
