/**
 *@file qtablero.h
 *@brief Este archivo contiene la definicion de la clase Qtablero
 *que nos servira para poder crear el juego Sudoku version 2.0.
 *
 *@author Marlon Loayza
 *@author Adrian Aguilar
 *
 *@date 08/07/2013
 */
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
#include <QGridLayout>
#include <QTextLine>
#include <QLabel>
#include <QErrorMessage>
#include <QLineEdit>
#include<QTextLine>





/**
   \mainpage Clase QTablero \n Lenguajes de programación
   <br>
   Profesor: Javier Tibau <br>
   <hr>
   \author Marlon Loayza
   \author Adrián Aguilar
   \date 08 de Julio del 2013

*/




namespace Ui {
class QTablero;
}

/**
 * @brief Clase que se encarga de generar y manejar eventos para el sudoku

 */
class QTablero : public QMainWindow
{
    Q_OBJECT
    
public:
    /**
     * @brief QTablero Constructor para el nuevo tablero
     * @param nombre Se ingresa el nombre del jugador para cada juego
     * @param parent El valor del contructor del padre, por default 0 para indicar que no tiene padre
     * @param d El valor de la difultad para cada tablero
     */
    explicit QTablero(QString nombre,QWidget *parent , int d);
    /**
     * @brief nombrejugador Variable donde se guarda el nombre del jugador
     */
    QString nombrejugador;

    /**
     * @brief dificultad Variable la cual nos indica la dificultad del juego
     */
    int dificultad;
    QString Aux;
    int habilitados[9][9];
    QStringList nombresjugadores;
    ~QTablero();
    
private slots:
    /**
     * @brief on_verificar_clicked
     *Señal que actua cuando el boton Verificar es pulsado
     *con el objetivo de verificar si el tablero esta correctamente lleno
     *
     */
    void on_verificar_clicked();
    /**
     * @brief control_ingreso_ficha
     *Funcion que verifica si una ficha a sido colocada correctamente en el
     *tablero, en caso de ser correcta otorga una cantidad de puntos para el
     *jugador.
     */
    void control_ingreso_ficha();
    /**
     * @brief on_actionExit_triggered Slot que actua cuando pulsan exit que nos permite cerrar la aplicacion
     */


    void on_actionExit_triggered();
    /**
     * @brief partida_nueva Funcion que nos permite crear un nuevo tablero con la dificultad dada
     * @param d Parametro que indica la dificultad con la que se generara el nuevo tablero
     */
    void partida_nueva(int d);
    /**
     * @brief verificarficha Funcion que nos permite verificar si un tablero esta correctamente lleno
     */
    void  verificarficha();
    /**
     * @brief verificarcolumna Funcion que me permite saber si una ficha esta ubicada correctamente en la columna
     * @param ficha recibe el valor de la ficha a verificar, l la posicion de la fila y m la posicion de la columna
     * @return Retorna 1 si esta correctamente ubicada y 0 si no debe ir ahi.
     */
    int  verificarcolumna(int ficha,int l, int m);
    void jugadores_archivo();
    void cargar_partidas(QString nombre);
    /**
     * @brief verificarfila Funcion que me permite verificar si un valor esta correctamente ubicada en la fila
     * @param ficha Es el valor de la ficha que vamos a verificar, l la posicion de la fila y m la posicion de la columna
     * @return Retorna 1 si esta correctamente ubicada y 0 si no lo está.
     */
    int  verificarfila(int ficha,int l, int m);
    /**
     * @brief verificarsubcuadricula Dada el valor de una ficha verifica si esta correctamente ubicada en la subcuadricula del tablero
     * @param ficha Es el valor de la ficha a verficar, l la posicion de la fila y m la posicion de la columna
     * @return Retorna 1 Si esta correctamente ubicada y 0 si no lo está
     */
    int verificarsubcuadricula(int ficha,int l, int m);
    /**
     * @brief inttoBinary Funcion que dado una valor decimal del 0 al 9 retorna su equivalencia en binario
     * @param i Es el valor a transformar
     * @return Equivalencia en binario
     */
    QString inttoBinary(int i);
    /**
     * @brief BinarytoInt Dada una cadena de caracteres de los numeros en binario del 0 al 9 retorna su equivalente en decimal
     * @param q Cadena a transformar
     * @return Retorna el valor decimal
     */
    int BinarytoInt(QString q);
    /**
     * @brief on_pushButton_clicked Funcion que llama a la señal de verificar el tablero lleno
     */
    void on_pushButton_clicked();
    /**
     * @brief on_pushButton_6_clicked Funcion que llama la ejecucion para cerrar la aplicacion
     */

    void on_pushButton_6_clicked();

    /**
     * @brief tiempo Funcion que crea nuevas variables para ejecutar el cronometro
     */

    void tiempo();
    /**
     * @brief tiempo1 funcion que va cambiando los segundos sucesivamente
     */
    void tiempo1();
    /**
     * @brief on_pushButton_2_clicked Funcion que verifica si el numero ingresado esta correcto
     * @param no recive ningun parametro
     */
    void on_pushButton_2_clicked();

    /**
     * @brief on_pushButton_4_clicked Funcion que guarda el tablero en un tiempo determinado
     * @param no recive ningun parametro
     */
    void on_pushButton_4_clicked();
    /**
     * @brief escribirTablero Funcion que carga una partida que haya sido guardada con anterioridad
     * @param no recive ningun parametro
     */
    void escribirTablero();
    /**
     * @brief initTablero funcion que asigna un valor a un arreglo de 81 casillas
     * @param nombre es el identificador del jugador y d es la dificultad del juego
     */
    void initTablero(QString nombre, int d);
    /**
     * @brief cargarTableroLleno funcion que crea un arreglo de 81 casillas de tipo QLineEdit
     * @param nombre_archivo es el nombre del archivo que vamos a cargar, nombre es el identificador del jugador y d es la dificultad del juego
     */
    void cargarTableroLleno(const QString &nombre_archivo, QString nombre,int d);

private:
    QErrorMessage error;
    QStringList numeros,temporal;
    QStringList lineaCompleta;
    QString Linea;
    int minuto, min1, m2, segundo, seg1, seg2, mseg, n1, n2;
    int seg;
    int min;
    QString contpuntos;
    QLabel *puntaje,*puntos,*jugador;
    QTimer *time;
    QTime *tm;
    QTime inicio;
    QPushButton *Verificar;
    Ui::QTablero *ui;
    QLineEdit *numbersButton[9][9];
    //QPushButton *numbers[9];
    QLineEdit  *numbersButton1[9][9];
    QLineEdit  *numbersButton2[9][9];
};

#endif // QTABLERO_H
