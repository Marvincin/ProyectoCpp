#include "qtablero.h"
#include "ui_qtablero.h"
#include <QGridLayout>
#include <QLine>
#include<QTextLine>
#include<QPushButton>


int num;

QTablero::QTablero(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::QTablero)
{
    ui->setupUi(this);
    initTablero();
   // verificar();
}

QTablero::~QTablero()
{
    delete ui;
    for(int i =0 ; i<9 ;i ++)
        for(int j=0; j<9 ; j++)
            delete numbersButton[i][j];
}



void QTablero::initTablero()
{
    cargarTableroLleno("Sudoku1.txt");
}

void QTablero::cargarTableroLleno(const QString &nombre_archivo)
{
    QFile archivo(nombre_archivo);
    QTime *seed = new QTime;
    int aleatox=0, aleatoy=0;
    seed->start(); //Para inicializar el puntero seed con la hora actual.
    qsrand(seed->msec()); //La semilla para qrand();
    archivo.open(QIODevice::Text | QIODevice::ReadOnly);
    if(!archivo.exists())
    {
        error.showMessage("El archivo no existe");
    }
    else
    {
        QTextStream palabra(&archivo);
        Linea = palabra.readLine();
        lineaCompleta = Linea.split(",");
        for(int i=0; i<9 ; i++)
        {
            for(int j =0 ; j<9 ; j++)
            {

                numbersButton[i][j]= new QTextEdit((lineaCompleta.at(j)));
                numbersButton1[i][j]= new QTextEdit((lineaCompleta.at(j)));
                numbersButton2[i][j]= new QTextEdit((lineaCompleta.at(j)));  //aqui debe ir los numeros aleatorios con los ceros
                numbersButton2[i][j]->setMaximumSize(25,25);
               // ui->gridLayout->addWidget(numbersButton2[i][j],i,j); // aqui en realidad debe agregarce el numbersbutton2

            }
         Linea = palabra.readLine();
         lineaCompleta = Linea.split(",");
        }
    }

    for(int i=0; i<17 ; i++)
    {
        aleatox=rand()%9;
        aleatoy=rand()%9;
        qDebug() << aleatox;
        qDebug() << aleatoy;
        if(numbersButton2[aleatox][aleatoy]->isEnabled())
        {
             numbersButton2[aleatox][aleatoy]->setEnabled(false);
              ui->gridLayout->addWidget(numbersButton2[aleatox][aleatoy],aleatox,aleatoy);
             numbersButton2[aleatox][aleatoy]->setStyleSheet("background : celestial");
        }
        else{
            i--;

        }
    }


    for(int i=0; i<9 ; i++)
    {
        for(int j =0 ; j<9 ; j++)
    {
        if(numbersButton2[i][j]->isEnabled())
        {
             numbersButton2[i][j]->setText( 0);
             numbersButton1[i][j]->setText( 0);
             ui->gridLayout->addWidget(numbersButton2[i][j],i,j);

        }
    }
    }

    archivo.flush();
    archivo.close();
}

void QTablero::control_ingreso_ficha()
{
 int k=0;

    for(int i=0; i<9 ; i++)
    {
        for(int j =0 ; j<9 ; j++)
    {
            if(numbersButton1[i][j]->toPlainText().toInt()!=numbersButton2[i][j]->toPlainText().toInt()){
                if (verificarfila(numbersButton2[i][j]->toPlainText().toInt())==0){
                    error.showMessage("numero erroneo");
                }else k++;
                if(verificarsubcuadricula(numbersButton2[i][j]->toPlainText().toInt())==0){
                    error.showMessage("numeero erroneo");
                }else k++;
                if(verificarcolumna(numbersButton2[i][j]->toPlainText().toInt())==0){
                    error.showMessage("numero erroneo");
                }else k++;

                if(k==3){ numbersButton1[i][j]->setText( numbersButton2[i][j]->toPlainText());}


            }


        }
    }






}

void QTablero::escribirTablero()
{
    QFile archivo("Sudoku1.txt");
    archivo.open(QIODevice::Text | QIODevice::WriteOnly);
    if(!archivo.isOpen()){ error.showMessage("El archivo esta abierto");}
        QTextStream txtstr(&archivo);
        txtstr << "Hola Mundo";
        error.showMessage("Se creo el archivo");
    archivo.flush();
    archivo.close();
}

int QTablero:: verificarcolumna(int ficha){
    for(int i=0; i<9 ; i++){
        num=0;
        for(int j=0; j<9 ; j++){

        if(numbersButton2[i][j]->toPlainText().toInt() ==ficha)
        {
           num++;
           break;
        }
        if(num>1){
                return 0;
                break;
        }else{
                return 1;

            }
       }

    }

}


int QTablero:: verificarsubcuadricula(int ficha){
    for(int s=1 ; s<10 ; s++){

      for(int h=0 ; h<7 ; h=h+3){

        for(int k=0 ; k<7 ; k=k+3){
           num=0;
           for(int i=0+h ; i<3+h ; i++){
               for(int j=0+k; j<3+k ; j++){
                     if(numbersButton2[i][j]->toPlainText().toInt() ==s)
                       {
                         num++;
                         break;
                       }
                      }
                     }if(num>1){
                        return 0;
                       break;
                       } else{
                        return 1;
                           }
                        }
        }
    }

}



int QTablero:: verificarfila(int ficha){
    for(int i=0; i<9 ; i++){
        num=0;
      for(int j=0; j<9 ; j++){
        if(numbersButton2[i][j]->toPlainText().toInt() ==ficha)
        {
           num++;
           break;
        }
        if(num>1){
                return 0;
                break;
        }else{
               return 1;

            }


    }

 }

}



void QTablero:: verificarficha(){


    numeros << "1" << "2" << "3" << "4" << "5" << "6" << "7" << "8" << "9";
    for(int i=0; i<9; i++)
        temporal.append(numeros.at(i));
    for(int i=0; i<9 ; i++)
    {
        for(int j=0; j<9; j++)
        {

            if(numbersButton2[i][j]->toPlainText().toInt() == 0)
            {
               error.showMessage("El tablero no esta correcto");
               break;
            }
            else

               error.showMessage("El tablero esta correcto");
        }
    }



   // valida columnas

    for(int i=0; i<9 ; i++){
        num=0;
        for(int j=0; j<9 ; j++){

        if(numbersButton2[i][j]->toPlainText().toInt() ==i+1)
        {
           num++;
           break;
        }
        if(num>1){
                error.showMessage("Las columnas estan incorrectas");
                break;
        }else{
                error.showMessage("Las columnas estan correctas");

            }
       }

    }

    // valida filas

    for(int i=0; i<9 ; i++){
        num=0;
      for(int j=0; j<9 ; j++){
        if(numbersButton2[i][j]->toPlainText().toInt() ==j+1)
        {
           num++;
           break;
        }
        if(num>1){
                error.showMessage("Las filas estan incorrectas");
                break;
        }else{
                error.showMessage("Las filas estan correctas");

            }


    }

 }

    //verificar subcuadriculas
    for(int s=1 ; s<10 ; s++){

      for(int h=0 ; h<7 ; h=h+3){

        for(int k=0 ; k<7 ; k=k+3){
           num=0;
           for(int i=0+h ; i<3+h ; i++){
               for(int j=0+k; j<3+k ; j++){
                     if(numbersButton2[i][j]->toPlainText().toInt() ==s)
                       {
                         num++;
                         break;
                       }
                      }
                     }if(num>1){
                        error.showMessage("Las subcuadriculas estan incorrectas");
                       break;
                       } else{
                        error.showMessage("Las subcuadriculas estan correctas");
                           }
                        }
        }
    }
}


 void QTablero::on_verificar_clicked()
 {
     verificarficha();

    }




void QTablero::on_actionExit_triggered()
{
    qApp ->quit();
}

void QTablero::on_pushButton_clicked()
{
    on_verificar_clicked();
}

void QTablero::on_pushButton_6_clicked()
{
    qApp ->quit();
}
