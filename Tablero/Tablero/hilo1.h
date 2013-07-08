#ifndef HILO1_H
#define HILO1_H

#include <QWidget>

namespace Ui {
class hilo1;
}

class hilo1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit hilo1(QWidget *parent = 0);
     int h,m,s;
    ~hilo1();
    
private:
    Ui::hilo1 *ui;
};

#endif // HILO1_H
