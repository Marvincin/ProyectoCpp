#include "hilo.h"
#include "qtablero.h"

void hilo::run()
{
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
        //ventana->lcdNumber->setProperty("intValue",s);
        msleep(1000);
    }
}
