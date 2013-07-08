#include "numeros.h"
#include "ui_numeros.h"

Numeros::Numeros(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Numeros)
{
    ui->setupUi(this);
}

Numeros::~Numeros()
{
    delete ui;
}

void Numeros::on_buttonBox_accepted()
{
    extraer_texto(numero1);
}

void Numeros::extraer_texto(QString valor)
{
    valor=ui->lineEdit->text();
}
