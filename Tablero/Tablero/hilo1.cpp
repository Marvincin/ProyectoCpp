#include "hilo1.h"
#include "ui_hilo1.h"

hilo1::hilo1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::hilo1)
{
    ui->setupUi(this);

        while(1){
            if(s==59){
                s=0;
                m++;
            }
            if(m==59){
                m=0;
                h++;

            }

            s++;
           ui->lcdNumber->setProperty("intValue",s);
            //slsleep(1000);
        }

}

hilo1::~hilo1()
{
    delete ui;
}
