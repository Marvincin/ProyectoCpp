#ifndef NUMEROS_H
#define NUMEROS_H

#include <QDialog>

namespace Ui {
class Numeros;
}

class Numeros : public QDialog
{
    Q_OBJECT
    
public:
    explicit Numeros(QWidget *parent = 0);
    QString numero1;
    ~Numeros();
    
private slots:
    void on_buttonBox_accepted();
    void extraer_texto(QString valor);

private:
    Ui::Numeros *ui;
};

#endif // NUMEROS_H
