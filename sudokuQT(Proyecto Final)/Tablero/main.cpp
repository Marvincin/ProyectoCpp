#include "qtablero.h"
#include <QApplication>
#include "principal.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    principal *w1= new principal();
    w1->show();
    //QTablero w;
    //w.show();
    
    return a.exec();
}
