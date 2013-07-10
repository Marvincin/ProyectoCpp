#include "principal.h"
#include "ui_principal.h"
#include "nivel.h"

principal::principal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::principal)
{
    ui->setupUi(this);
}

principal::~principal()
{
    delete ui;
}

void principal::on_pushButton_clicked()
{
    w = new nivel();
    w->show();
    this->setVisible(false);
}

void principal::on_pushButton_3_clicked()
{
    qApp ->quit();
}

void principal::on_pushButton_4_clicked()
{

}

void principal::on_pushButton_2_clicked()
{

}
