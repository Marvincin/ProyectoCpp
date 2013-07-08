#include "qtablero.h"
#include "ui_qtablero.h"
#include <QGridLayout>
#include <QLine>
#include <QTimer>
#include "ui_nivel.h"
//#include "nivel.h"
#include<QTextLine>
#include<QPushButton>
#include "hilo1.h"
#include <QtConcurrent/QtConcurrentRun>


int num;
int aleatox=0, aleatoy=0;
int contpuntos=10;



QTablero::QTablero(QString nombre,QWidget *parent,int d) :
    QMainWindow(parent),
    ui(new Ui::QTablero)
{
    ui->setupUi(this);
    initTablero(nombre,d);
   // verificar();
}

QTablero::~QTablero()
{
    delete ui;
    for(int i =0 ; i<9 ;i ++)
        for(int j=0; j<9 ; j++)
            delete numbersButton[i][j];
}



void QTablero::initTablero(QString nombre,int d)
{
    cargarTableroLleno(":/Sudoku1.txt", nombre,d);
}







void QTablero::cargarTableroLleno(const QString &nombre_archivo, QString nombre,int d)
{
    QFile archivo(nombre_archivo);
    QTime *seed = new QTime;

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



        //QtConcurrent::run(this,&QTablero::time);

        for(int i=0; i<9 ; i++)
        {
            for(int j =0 ; j<9 ; j++)
            {


                numbersButton[i][j]= new QPushButton((lineaCompleta.at(j)));
                numbersButton1[i][j]= new QPushButton((lineaCompleta.at(j)));
                numbersButton2[i][j]= new QPushButton((lineaCompleta.at(j)));  //aqui debe ir los numeros aleatorios con los ceros
                numbersButton2[i][j]->setMaximumSize(40,40);
                numbersButton2[i][j]->setIconSize(QSize(45,45));
                numbersButton2[i][j]->setIcon(QIcon(":/images/0.png"));
                }
         Linea = palabra.readLine();
         lineaCompleta = Linea.split(",");
        }

        for(int i=0;i<9;i++){
            numbers[i]=new QPushButton();
            numbers[i]->setIconSize(QSize(40,40));
            numbers[i]->setMaximumSize(34,35);
            if(i==0){numbers[i]->setIcon(QIcon(":/images/1.png"));numbers[i]->setText(QString(i));}
                 if(i==1){numbers[i]->setIcon(QIcon(":/images/2.png"));numbers[i]->setText(QString(i));}
                      if(i==2){numbers[i]->setIcon(QIcon(":/images/3.png"));numbers[i]->setText(QString(i));}
                           if(i==3){numbers[i]->setIcon(QIcon(":/images/4.png"));numbers[i]->setText(QString(i));}
                                if(i==4){numbers[i]->setIcon(QIcon(":/images/5.png"));numbers[i]->setText(QString(i));}
                                     if(i==5){numbers[i]->setIcon(QIcon(":/images/6.png"));numbers[i]->setText(QString(i));}
                                          if(i==6){numbers[i]->setIcon(QIcon(":/images/7.png"));numbers[i]->setText(QString(i));}
                                               if(i==7){numbers[i]->setIcon(QIcon(":/images/8.png"));numbers[i]->setText(QString(i));}
                                                    if(i==8){numbers[i]->setIcon(QIcon(":/images/9.png"));numbers[i]->setText(QString(i));}



        }



        jugador=new QLabel();
        jugador->setText(nombre);
        puntos= new QLabel();
        puntos->setText(QString(contpuntos));
        //tiempo= new QLabel();
        //tiempo->setText("00:00:00");

        partida_nueva(d);


    }


    archivo.flush();
    archivo.close();
}

void QTablero::partida_nueva(int d){

    int a=0;



    for(int i=0; i<9 ; i++)
    {
        ui->horizontalLayout->addWidget(numbers[i],i);

    }

    ui->gridLayout_2->addWidget(new QLabel("Jugador:"),1,0);
    ui->gridLayout_2->addWidget(jugador,1,1);
    ui->gridLayout_2->addWidget(new QLabel("Puntaje"),2,0);
    ui->gridLayout_2->addWidget(puntos,2,2);

   // ui->reloj->addWidget(h);
   //ui->gridLayout_2->addWidget(tiempo,3,3);


    if(d==1){
        a=33;
    }
    if(d==2){
        a=25;
      }
    if(d==3){
        a=19;
      }

    for(int i=0; i<=a ; i++)
    {
        aleatox=rand()%9;
        aleatoy=rand()%9;
        qDebug() << aleatox;
        qDebug() << aleatoy;
        if(numbersButton2[aleatox][aleatoy]->isEnabled())
        {
            //numbersButton2[aleatox][aleatoy]->setEnabled(false);
             if(numbersButton2[aleatox][aleatoy]->text().toInt()==1){
                   numbersButton2[aleatox][aleatoy]->setIcon(QIcon(":/images/pista1.png"));
               }
             if(numbersButton2[aleatox][aleatoy]->text().toInt()==2){
                      numbersButton2[aleatox][aleatoy]->setIcon(QIcon(":/images/pista2.png"));
              }
             if(numbersButton2[aleatox][aleatoy]->text().toInt()==3){
                          numbersButton2[aleatox][aleatoy]->setIcon(QIcon(":/images/pista3.png"));
              }
             if(numbersButton2[aleatox][aleatoy]->text().toInt()==4){
                              numbersButton2[aleatox][aleatoy]->setIcon(QIcon(":/images/pista4.png"));
              }
             if(numbersButton2[aleatox][aleatoy]->text().toInt()==5){
                                  numbersButton2[aleatox][aleatoy]->setIcon(QIcon(":/images/pista5.png"));
              }
             if(numbersButton2[aleatox][aleatoy]->text().toInt()==6){
                                      numbersButton2[aleatox][aleatoy]->setIcon(QIcon(":/images/pista6.png"));
              }
             if(numbersButton2[aleatox][aleatoy]->text().toInt()==7){
                                          numbersButton2[aleatox][aleatoy]->setIcon(QIcon(":/images/pista7.png"));
                }
              if(numbersButton2[aleatox][aleatoy]->text().toInt()==8){
                                              numbersButton2[aleatox][aleatoy]->setIcon(QIcon(":/images/pista8.png"));
                }
              if(numbersButton2[aleatox][aleatoy]->text().toInt()==9){
                                                     numbersButton2[aleatox][aleatoy]->setIcon(QIcon(":/images/pista9.png"));

               }
                habilitados[aleatox][aleatoy]=1;
               ui->gridLayout->addWidget(numbersButton2[aleatox][aleatoy],aleatox,aleatoy);


        }
        else{
            i--;

        }
       }


    for(int i=0; i<9 ; i++)
    {
        for(int j =0 ; j<9 ; j++)
    {
        if(habilitados[i][j]!=1)
        {

             numbersButton1[i][j]->setText(0);
             habilitados[i][j]=0;
             numbersButton2[i][j]->setText(0);
        }
        connect(numbersButton2[i][j],&QPushButton::clicked,this,&QTablero::on_pushButton_2_clicked);
        ui->gridLayout->addWidget(numbersButton2[i][j],i,j);
    }
    }
}

void QTablero::on_pushButton_2_clicked()
{



    ventana=new QWidget();
    ventana->resize(100,100);
    q=new QGridLayout();


    tex = new QLineEdit();
    tex->setMaximumSize(40,20);
    q->addWidget(tex,1,1);
    q->addWidget(new QLabel("Ingrese el numero"),1,0);
    aceptar=new QPushButton("aceptar");
    boton_salir=new QPushButton("Salir");
     boton_salir->resize(50, 50);
     aceptar->resize(50, 50);
     q->addWidget(boton_salir,3,0);
     q->addWidget(aceptar,3,2);
      ventana->setLayout(q);
     ventana->show();

     connect(boton_salir,&QPushButton::clicked,this,&QTablero::limpiar);
     connect(aceptar,&QPushButton::clicked,this,&QTablero::cambiarficha);


}

void QTablero::cambiarficha(){
    ventana->setVisible(false);
    if(tex->text()==""){
        error.showMessage("ingrese un numero valido");
    }else{

        for(int i=0; i<9 ; i++)
        {
            for(int j =0 ; j<9 ; j++)
        {
                if(numbersButton2[i][j]->isChecked()== true ){

                     numbersButton2[i][j]->setText(tex->text());

                     if(tex->text().toInt()==1){
                           numbersButton2[i][j]->setIcon(QIcon(":/images/pista1.png"));
                       }
                     if(tex->text().toInt()==2){
                              numbersButton2[i][j]->setIcon(QIcon(":/images/pista2.png"));
                      }
                     if(tex->text().toInt()==3){
                                  numbersButton2[i][j]->setIcon(QIcon(":/images/pista3.png"));
                      }
                     if(tex->text().toInt()==4){
                                      numbersButton2[i][j]->setIcon(QIcon(":/images/pista4.png"));
                      }
                     if(tex->text().toInt()==5){
                                          numbersButton2[i][j]->setIcon(QIcon(":/images/pista5.png"));
                      }
                     if(tex->text().toInt()==6){
                                              numbersButton2[i][j]->setIcon(QIcon(":/images/pista6.png"));
                      }
                     if(tex->text().toInt()==7){
                                                  numbersButton2[i][j]->setIcon(QIcon(":/images/pista7.png"));
                        }
                      if(tex->text().toInt()==8){
                                                      numbersButton2[i][j]->setIcon(QIcon(":/images/pista8.png"));
                        }
                      if(tex->text().toInt()==9){
                                                             numbersButton2[i][j]->setIcon(QIcon(":/images/pista9.png"));

                       }

                    }
            }
        }


    }


}



void QTablero::limpiar(){

    tex->setText("");
    ventana->setVisible(false);
}



void QTablero::control_ingreso_ficha()
{
 int k=0;

    for(int i=0; i<9 ; i++)
    {
        for(int j =0 ; j<9 ; j++)
    {
            if(numbersButton1[i][j]->text().toInt()!=numbersButton2[i][j]->text().toInt()){
                if (verificarfila(numbersButton2[i][j]->text().toInt())==0){
                    error.showMessage("numero erroneo");
                }else k++;
                if(verificarsubcuadricula(numbersButton2[i][j]->text().toInt())==0){
                    error.showMessage("numeero erroneo");
                }else k++;
                if(verificarcolumna(numbersButton2[i][j]->text().toInt())==0){
                    error.showMessage("numero erroneo");
                }else k++;

                if(k==3){ numbersButton1[i][j]->setText( numbersButton2[i][j]->text());
                  contpuntos= contpuntos+10;
                }


            }


        }
    }






}

void QTablero::escribirTablero()
{
    QFile archivo("../Tablero/SudokuJug.txt");
    archivo.open(QIODevice::Text | QIODevice::Append);
    if(!archivo.isOpen()){ error.showMessage("El archivo esta abierto");}
        QTextStream txtstr(&archivo);
        txtstr << jugador->text();
        txtstr << "\n";
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                txtstr << inttoBinary(numbersButton2[i][j]->text().toInt());
                txtstr << ",";
                txtstr << inttoBinary(numbersButton[i][j]->text().toInt());
                txtstr << ",";
            }
            txtstr << "\n";
            for(int j=0;j<9;j++)
            {
                if(habilitados[i][j]!=0)
                    txtstr << "1,";
                else
                    txtstr << "0,";
            }
            txtstr << "\n";
        }
    archivo.flush();
    archivo.close();
}

int QTablero:: verificarcolumna(int B){
    for(int i=0; i<9 ; i++){
        num=0;
        for(int j=0; j<9 ; j++){

            if(numbersButton2[i][j]->text().toInt() ==B)
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
                     if(numbersButton2[i][j]->text().toInt() ==s)
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
        if(numbersButton2[i][j]->text().toInt() ==ficha)
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

            if(numbersButton2[i][j]->text().toInt() == 0)
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

        if(numbersButton2[i][j]->text().toInt() ==i+1)
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
        if(numbersButton2[i][j]->text().toInt() ==j+1)
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
                     if(numbersButton2[i][j]->text().toInt() ==s)
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



QString QTablero::inttoBinary(int i){
    if(i==0)
        return "0000";
    if(i==1)
        return "0001";
    if(i==2)
        return "0010";
    if(i==3)
        return "0011";
    if(i==4)
        return "0100";
    if(i==5)
        return "0101";
    if(i==6)
        return "0110";
    if(i==7)
        return "0111";
    if(i==8)
        return "1000";
    if(i==9)
        return "1001";

}
int QTablero::BinarytoInt(QString q){
    if(q=="0000")
        return 0;
    if(q=="0001")
        return 1;
    if(q=="0010")
        return 2;
    if(q=="0011")
        return 3;
    if(q=="0100")
        return 4;
    if(q=="0101")
        return 5;
    if(q=="0110")
        return 6;
    if(q=="0111")
        return 7;
    if(q=="1000")
        return 8;
    if(q=="1001")
        return 9;

}




void QTablero::on_pushButton_4_clicked()
{
    escribirTablero();
    error.showMessage("El juego se guardo correctamente");

}

void QTablero::jugadores_archivo()
{
    QFile archivo("../Tablero/SudokuJug.txt");
    int multiplicador=0;
    archivo.open(QIODevice::Text | QIODevice::ReadOnly);
    if(!archivo.exists())
        error.showMessage("El archivo no existe");
    else
    {
        QTextStream palabra(&archivo);

        Linea = palabra.readAll();
        lineaCompleta=Linea.split("\n");
        for(int contador=0; contador<lineaCompleta.size(); contador ++)
        {
            if(contador == multiplicador*18 + multiplicador || contador==0)
            {
              nombresjugadores.append(lineaCompleta[contador]);
              multiplicador++;
            }
        }

    }
    archivo.flush();
    archivo.close();
}

void QTablero::cargar_partidas(QString nombre)
{
    QStringList Caracteres;
    int pos=0;
    int multiplicador=0;
    QFile archivo("../Tablero/SudokuJug.txt");
    archivo.open(QIODevice::Text | QIODevice::ReadOnly);
    if(!archivo.exists())
        error.showMessage("El archivo no existe");
    else
    {
        QTextStream palabra(&archivo);
        Linea = palabra.readAll();
        lineaCompleta = Linea.split("\n");
        for(int contador; contador<lineaCompleta.size();contador ++)
        {
           if(contador == multiplicador*18 + multiplicador || contador==0)
            {
                if(lineaCompleta.at(contador)==nombre)
                {
                    jugador->setText(nombre);
                    for(int contad=0;contad<9;contad++)
                    {
                        Caracteres = lineaCompleta.at(contador+contad+1).split(",");
                            for(int contador2=0; contador2<9; contador2++)
                            {
                                numbersButton2[contad][contador2]->setText(Caracteres.at(pos));
                                numbersButton1[contad][contador2]->setText(Caracteres.at(pos));
                                pos++;
                                numbersButton[contad][contador2]->setText(Caracteres.at(pos));
                                pos++;
                            }
                        Caracteres = lineaCompleta.at(contador+contad+1).split(",");
                        for(int contador2=0; contador2<9; contador2++)

                        {
                                   habilitados[contad][contador2]=Caracteres.at(contador).toInt();
                        }
                    }
                }
            }

        }
    }
}
