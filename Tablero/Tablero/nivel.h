#ifndef NIVEL_H
#define NIVEL_H

#include <QDialog>
#include "qtablero.h"

namespace Ui {
class nivel;
}

class nivel : public QDialog
{
    Q_OBJECT
    
public:
    explicit nivel(QWidget *parent = 0);
    int partida;
    QString nom;
    QTablero  *w1;
    ~nivel();
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::nivel *ui;

};


#endif // NIVEL_H
