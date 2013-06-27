#ifndef QTABLERO_H
#define QTABLERO_H

#include <QMainWindow>
#include <QApplication>
#include <QFile>
#include <QTime>
#include <QDebug>
#include <QTextStream>
#include <QString>
#include <QPushButton>
#include <QLabel>
#include <QErrorMessage>
#include <QTextEdit>


namespace Ui {
class QTablero;
}

class QTablero : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit QTablero(QWidget *parent = 0);
    ~QTablero();
    
private slots:

    void on_verificar_clicked();

    void QTablero::control_ingreso_ficha();

    void on_actionExit_triggered();

    void QTablero:: verificarficha();
    int QTablero:: verificarcolumna(int ficha);
    int QTablero:: verificarfila(int ficha);
    int QTablero:: verificarsubcuadricula(int ficha);

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

private:
    QErrorMessage error;
    QStringList numeros,temporal;
    QStringList lineaCompleta;
    QString Linea;

    QPushButton *Verificar;
    void escribirTablero();
    void initTablero();

    void cargarTableroLleno(const QString &nombre_archivo);
    Ui::QTablero *ui;
    QTextEdit *numbersButton[9][9];
    QTextEdit *numbersButton1[9][9];
    QTextEdit *numbersButton2[9][9];
};

#endif // QTABLERO_H
