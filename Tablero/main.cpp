#include "qtablero.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTablero w;
    w.show();
    
    return a.exec();
}
