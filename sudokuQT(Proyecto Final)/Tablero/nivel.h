/**
* @file nivel.h
* @brief en esta clase se selecciona el nivel de dificultad del juego y el nombre del jugador
*
* @author Adrian Aguilar
* @author Marlon loayza
*
*/


#ifndef NIVEL_H
#define NIVEL_H

#include <QDialog>
#include "qtablero.h"

namespace Ui {
class nivel;
}
/**
 * @brief nivel nos envia parametros para poder formar el sudoku segun sus dificultades
 */

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
    /**
     * @brief on_pushButton_2_clicked regresa al menu principal
     */
    void on_pushButton_2_clicked();
    /**
     * @brief on_pushButton_clicked crea el nuevo sudoku segun su dificultad
     */
    void on_pushButton_clicked();

private:
    Ui::nivel *ui;

};


#endif // NIVEL_H
