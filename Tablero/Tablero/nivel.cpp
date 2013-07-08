#include "nivel.h"
#include "ui_nivel.h"
#include "qtablero.h"

nivel::nivel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::nivel)
{
    ui->setupUi(this);
}

nivel::~nivel()
{
    delete ui;
}

void nivel::on_pushButton_2_clicked()
{
    this->setVisible(false);
}

void nivel::on_pushButton_clicked()
{
    int d=0;
    if(ui->facil->isChecked()){
        d=1;
    }
    if(ui->medio->isChecked()){
        d=2;
    }
    if(ui->dificil->isChecked()){
        d=3;
    }
    QWidget *parent=0;
    w1=new QTablero(ui->nombretexto->text(),parent ,d);

    //if(ui->facil->isChecked()){
   //     w1->dificultad=1;
   // }
   // if(ui->medio->isChecked()){
   //     w1->dificultad=2;
   // }
   // if(ui->dificil->isChecked()){
   //     w1->dificultad=3;
   // }
    //w1->dificultad=1;
    nom=ui->nombretexto->text();
    w1->nombrejugador=nom;
    w1->show();
    this->setVisible(false);
}
