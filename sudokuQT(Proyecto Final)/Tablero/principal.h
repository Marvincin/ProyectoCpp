/**
* @file principal.h
* @brief Clase encargada de seleccionar un juego nuevo y cargar partidas guardadas
* @author Adrian Aguilar
* @author Marlon loaiza
*
*/

#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "nivel.h"
#include <QDialog>

namespace Ui {
class principal;
}

/**
 * @brief principal esta clase es para generar un juego nuevo  o cargar una partida y ver los mejores puntajes
 */
class principal : public QDialog
{
    Q_OBJECT
    
public:
    explicit principal(QWidget *parent = 0);
    nivel *w;
    ~principal();
    
private slots:
    /**
     * @brief on_pushButton_clicked crea una ventana que nos permitira elegir la dificultad del juego
     */
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::principal *ui;
};

#endif // PRINCIPAL_H
