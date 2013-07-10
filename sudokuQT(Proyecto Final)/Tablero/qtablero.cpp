#include "qtablero.h"
#include "ui_qtablero.h"
#include <QGridLayout>
#include <QLine>
#include <QTimer>
#include "ui_nivel.h"
#include<QTextLine>
#include<QPushButton>
#include <QtConcurrent/QtConcurrentRun>
#include <QDoubleValidator>
#include <QMessageBox>


int num;
int aleatox=0, aleatoy=0;




QTablero::QTablero(QString nombre,QWidget *parent,int d) :
    QMainWindow(parent),
    ui(new Ui::QTablero)
{
    ui->setupUi(this);

    initTablero(nombre,d);

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

        QValidator *inputRange = new QDoubleValidator(1, 9, 0, this);
        for(int i=0; i<9 ; i++)
        {
            for(int j =0 ; j<9 ; j++)
            {


                numbersButton[i][j]= new QLineEdit((lineaCompleta.at(j)));

                numbersButton1[i][j]= new QLineEdit((lineaCompleta.at(j)));
                numbersButton2[i][j]= new QLineEdit((lineaCompleta.at(j)));  //aqui debe ir los numeros aleatorios con los ceros

                numbersButton2[i][j]->setValidator(inputRange);
                numbersButton2[i][j]->setMaxLength(1);

                connect(numbersButton1[i][j],SIGNAL(),this,SLOT(on_pushButton_2_clicked()));

                }
         Linea = palabra.readLine();
         lineaCompleta = Linea.split(",");
        }

       contpuntos="0";

        jugador=new QLabel();
        jugador->setText(nombre);
        puntos= new QLabel();
        puntos->setText(contpuntos);

        QPalette Pal = ui->lcdNumber->palette();
        Pal.setColor(QPalette::Normal, QPalette::WindowText, Qt::green);
        Pal.setColor(QPalette::Normal, QPalette::Window, Qt::black);
        ui->lcdNumber->setPalette(Pal);

        partida_nueva(d);


    }


    archivo.flush();
    archivo.close();
}






void QTablero::tiempo()
{
    time = new QTimer(this);
    connect(time, SIGNAL(timeout()), this, SLOT(tiempo1()));
    time->start(1000);
    inicio = QTime::currentTime();
    QTimer::singleShot(1000, this, SLOT(tiempo1()));
}


void QTablero::tiempo1()
{
    minuto=segundo= mseg=0;
    min1=seg1=n1=0;
    m2=seg2= n2 = 0;
    QTime act = QTime::currentTime();
    min1 = inicio.minute();
    seg1 = inicio.second();
    n1 = inicio.msec();
    m2 = act.minute();
    seg2 = act.second();
    n2 = act.msec();

    if (n2 < n1)
    {
        n2 = 1000 + n2;
        seg2 = seg2 -1;
    }

    if (seg2 < seg1)
    {
        seg2 = 60 + seg2;
    m2 = m2 -1;
    }

    minuto = m2 - min1 +min;
    segundo = seg2 - seg1 +seg;
    mseg = n2 - n1;
    qDebug("%d:%d:%d",minuto,segundo,mseg);
    qDebug("%d,%d",min,seg);

    tm->setHMS(0, minuto, segundo, mseg);
    ui->lcdNumber->display(tm->toString("mm:ss"));
}





void QTablero::partida_nueva(int d){

    int a=0;
    min = 0;
    seg = 0;
     tm = new QTime(0,0,0,0);


    ui->gridLayout_2->addWidget(new QLabel("Jugador:"),1,0);
    ui->gridLayout_2->addWidget(jugador,1,1);
    ui->gridLayout_2->addWidget(new QLabel("Puntaje"),2,0);
    ui->gridLayout_2->addWidget(puntos,2,2);



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

        if(numbersButton2[aleatox][aleatoy]->isEnabled()){
        numbersButton2[aleatox][aleatoy]->setEnabled(false);
          }else i--;
        if(aleatox>=0 && aleatox<=2 && aleatoy>=0 && aleatoy<=2 )
        {

            ui->celda1->addWidget(numbersButton2[aleatox][aleatoy],aleatox,aleatoy);
        }

        if(aleatox>=0 && aleatox<=2 && aleatoy>=3 && aleatoy<=5){

            ui->celda2->addWidget(numbersButton2[aleatox][aleatoy],aleatox,(aleatoy-3));
        }
        if(aleatox>=0 && aleatox<=2 && aleatoy>=6 && aleatoy<=8){

            ui->celda3->addWidget(numbersButton2[aleatox][aleatoy],aleatox,(aleatoy-6));
        }


        if(aleatox>=3 && aleatox<=5 && aleatoy>=0 && aleatoy<=2){

            ui->celda4->addWidget(numbersButton2[aleatox][aleatoy],aleatox-3,aleatoy);
        }
        if(aleatox>=3 && aleatox<=5 && aleatoy>=3 && aleatoy<=5){

            ui->celda5->addWidget(numbersButton2[aleatox][aleatoy],aleatox-3,aleatoy-3);
        }
        if(aleatox>=3 && aleatox<=5 && aleatoy>=6 && aleatoy<=8){

            ui->celda6->addWidget(numbersButton2[aleatox][aleatoy],aleatox-3,aleatoy-6);
        }
        if(aleatox>=6 && aleatox<=8 && aleatoy>=0 && aleatoy<=2){

            ui->celda7->addWidget(numbersButton2[aleatox][aleatoy],aleatox-6,aleatoy);
        }
        if(aleatox>=6 && aleatox<=8 && aleatoy>=3 && aleatoy<=5){

            ui->celda8->addWidget(numbersButton2[aleatox][aleatoy],aleatox-6,aleatoy-3);
        }
        if(aleatox>=6 && aleatox<=8 && aleatoy>=6 && aleatoy<=8){

            ui->celda9->addWidget(numbersButton2[aleatox][aleatoy],aleatox-6,aleatoy-6);
        }




       }


    for(int i=0; i<9 ; i++)
    {
        for(int j =0 ; j<9 ; j++)
    {
        if(numbersButton2[i][j]->isEnabled())
        {

             numbersButton1[i][j]->setText(0);
             numbersButton2[i][j]->setText(0);
             habilitados[i][j]= 0;

        }else{
            habilitados[i][j]= 1;
        }

        if(i>=0 && i<=2 && j>=0 && j<=2 )
        {

            ui->celda1->addWidget(numbersButton2[i][j],i,j);
        }

        if(i>=0 && i<=2 && j>=3 && j<=5){

            ui->celda2->addWidget(numbersButton2[i][j],i,(j-3));
        }
        if(i>=0 && i<=2 && j>=6 && j<=8){

            ui->celda3->addWidget(numbersButton2[i][j],i,(j-6));
        }


        if(i>=3 && i<=5 && j>=0 && j<=2){

            ui->celda4->addWidget(numbersButton2[i][j],i-3,j);
        }
        if(i>=3 && i<=5 && j>=3 && j<=5){

            ui->celda5->addWidget(numbersButton2[i][j],i-3,j-3);
        }
        if(i>=3 && i<=5 && j>=6 && j<=8){

            ui->celda6->addWidget(numbersButton2[i][j],i-3,j-6);
        }
        if(i>=6 && i<=8 && j>=0 && j<=2){

            ui->celda7->addWidget(numbersButton2[i][j],i-6,j);
        }
        if(i>=6 && i<=8 && j>=3 && j<=5){

            ui->celda8->addWidget(numbersButton2[i][j],i-6,j-3);
        }
        if(i>=6 && i<=8 && j>=6 && j<=8){

            ui->celda9->addWidget(numbersButton2[i][j],i-6,j-6);
        }


    }
    }


    tiempo();

}

void QTablero::on_pushButton_2_clicked()
{
    control_ingreso_ficha();
    verificarficha();


}





void QTablero::control_ingreso_ficha()
{


    for(int i=0; i<9 ; i++)
    {

        for(int j =0 ; j<9 ; j++)
    {
            if(numbersButton1[i][j]->text().toInt()!=numbersButton2[i][j]->text().toInt()){
                int k=0;

                if (verificarfila(numbersButton2[i][j]->text().toInt(),i,j)==0){
                    QMessageBox::warning(this,"Sudoku Message","número "+numbersButton2[i][j]->text()+" repetido en fila");

                }else k++;
                if(verificarsubcuadricula(numbersButton2[i][j]->text().toInt(),i,j)==0){
                     QMessageBox::warning(this,"Sudoku Message","número "+numbersButton2[i][j]->text()+" repetido en cuadricula");
                }else k++;
                if(verificarcolumna(numbersButton2[i][j]->text().toInt(),i,j)==0){
                     QMessageBox::warning(this,"Sudoku Message","número "+numbersButton2[i][j]->text()+" repetido en fila");
                }else k++;

                if(k==3){ numbersButton1[i][j]->setText( numbersButton2[i][j]->text());

                    contpuntos= QString::number(contpuntos.toInt()+20);
                    puntos->setText(contpuntos);
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
                if(!numbersButton2[i][j]->isEnabled())  //if(habilitados[i][j]!=0)
                    txtstr << "1,";
                else
                    txtstr << "0,";
            }
            txtstr << "\n";
        }
    archivo.flush();
    archivo.close();
}

int QTablero:: verificarcolumna(int B, int l, int m){
      num=0;
      int b=0;
        for(int j=0; j<9 ; j++){
         if(numbersButton2[l][j]->text().toInt() !=0){
             b++;
         }
            if(numbersButton2[l][j]->text().toInt() ==B)
        {
           num++;

        }
        if(num>1){
                return 0;

        }



       }
        if(b==9){
        contpuntos= QString::number(contpuntos.toInt()+40);
        puntos->setText(contpuntos);}
     return 1;

}


int QTablero:: verificarsubcuadricula(int ficha, int l, int m){
int b;
    if(l<=2 && m<=2){
num=0;b=0;
        for(int i=0 ; i<3 ; i++){
            for(int j=0; j<3 ; j++){
                if(numbersButton2[i][j]->text().toInt() !=0){
                 b++;
                }
                if(b==9){contpuntos= QString::number(contpuntos.toInt()+40);
                    puntos->setText(contpuntos);
                }
                  if(numbersButton2[i][j]->text().toInt() ==ficha)
                    {
                      num++;

                    }
                   }
                  }if(num>1){
                     return 0;

                    }



    }

    if(l<=2 && m>=3 && m<=5){
        num=0;b=0;
        for(int i=0 ; i<3 ; i++){
            for(int j=3; j<6 ; j++){
                if(numbersButton2[i][j]->text().toInt() !=0){
                 b++;
                }
                if(b==9){contpuntos= QString::number(contpuntos.toInt()+40);
                    puntos->setText(contpuntos);
                }
                  if(numbersButton2[i][j]->text().toInt() ==ficha)
                    {
                      num++;

                    }
                   }
                  }if(num>1){
                     return 0;

                    }

    }
    if(l<=2 && m>=6 && m<=8){
        num=0;b=0;
        for(int i=0 ; i<3 ; i++){
            for(int j=6; j<9 ; j++){
                if(numbersButton2[i][j]->text().toInt() !=0){
                 b++;
                }
                if(b==9){contpuntos= QString::number(contpuntos.toInt()+40);
                    puntos->setText(contpuntos);
                }
                  if(numbersButton2[i][j]->text().toInt() ==ficha)
                    {
                      num++;

                    }
                   }
                  }if(num>1){
                     return 0;

                    } else{
                     return 1;
                        }

    }


    if(l>=3&& l<=5 && m<=2){
        num=0;b=0;
        for(int i=3 ; i<6 ; i++){
            for(int j=0; j<3 ; j++){
                if(numbersButton2[i][j]->text().toInt() !=0){
                 b++;
                }
                if(b==9){contpuntos= QString::number(contpuntos.toInt()+40);
                    puntos->setText(contpuntos);
                }
                  if(numbersButton2[i][j]->text().toInt() ==ficha)
                    {
                      num++;

                    }
                   }
                  }if(num>1){
                     return 0;

                    }

    }

    if(l>=3&& l<=5 && m>=3 && m<=5){
        num=0;b=0;
        for(int i=3 ; i<6 ; i++){
            for(int j=3; j<6 ; j++){
                if(numbersButton2[i][j]->text().toInt() !=0){
                 b++;
                }
                if(b==9){contpuntos= QString::number(contpuntos.toInt()+40);
                    puntos->setText(contpuntos);
                }
                  if(numbersButton2[i][j]->text().toInt() ==ficha)
                    {
                      num++;

                    }
                   }
                  }if(num>1){
                     return 0;

                    }

    }
    if(l>=3&& l<=5 && m>=6 && m<=8){
        num=0;b=0;
        for(int i=3 ; i<6 ; i++){
            for(int j=6; j<9 ; j++){
                if(numbersButton2[i][j]->text().toInt() !=0){
                 b++;
                }
                if(b==9){contpuntos= QString::number(contpuntos.toInt()+40);
                    puntos->setText(contpuntos);
                }
                  if(numbersButton2[i][j]->text().toInt() ==ficha)
                    {
                      num++;

                    }
                   }
                  }if(num>1){
                     return 0;

                    }
    }


    if(l>=6&& l<=8 && m<=2){
        num=0;b=0;
        for(int i=6 ; i<9 ; i++){
            for(int j=0; j<3 ; j++){
                if(numbersButton2[i][j]->text().toInt() !=0){
                 b++;
                }
                if(b==9){contpuntos= QString::number(contpuntos.toInt()+40);
                    puntos->setText(contpuntos);
                }
                  if(numbersButton2[i][j]->text().toInt() ==ficha)
                    {
                      num++;

                    }
                   }
                  }if(num>1){
                     return 0;

                    }

    }

    if(l>=6&& l<=8 && m>=3 && m<=5){
        num=0;b=0;
        for(int i=6 ; i<9 ; i++){
            for(int j=3; j<6 ; j++){
                if(numbersButton2[i][j]->text().toInt() !=0){
                 b++;
                }
                if(b==9){contpuntos= QString::number(contpuntos.toInt()+40);
                    puntos->setText(contpuntos);
                }
                  if(numbersButton2[i][j]->text().toInt() ==ficha)
                    {
                      num++;

                    }
                   }
                  }if(num>1){
                     return 0;

                    }

    }
    if(l>=6&& l<=8 && m>=6 && m<=8){
        num=0;b=0;
        for(int i=6 ; i<9 ; i++){
            for(int j=6; j<9 ; j++){
                if(numbersButton2[i][j]->text().toInt() !=0){
                 b++;
                }
                if(b==9){contpuntos= QString::number(contpuntos.toInt()+40);
                    puntos->setText(contpuntos);
                }
                  if(numbersButton2[i][j]->text().toInt() ==ficha)
                    {
                      num++;

                    }
                   }
                  }if(num>1){
                     return 0;

                    }

    }

     return 1;

   }



int QTablero:: verificarfila(int ficha,int l, int m){
     num=0;
     int b=0;
      for(int j=0; j<9 ; j++){
       if(numbersButton2[j][m]->text().toInt() !=0){
        b++;
       }

        if(numbersButton2[j][m]->text().toInt() ==ficha)
        {
           num++;
           break;
        }
        if(num>1){
                return 0;
                break;
        }


    }
      if(b==9){
     contpuntos= QString::number(contpuntos.toInt()+40);
      puntos->setText(contpuntos);}

      return 1;



}



void QTablero:: verificarficha(){

int b=0;
    for(int i=0; i<9 ; i++)
    {
        for(int j=0; j<9; j++)
        {

            if(numbersButton2[i][j]->text().toInt() == 0)
            {
               b++;
            }
        }
    }
    if(b==0){
                    contpuntos= QString::number(contpuntos.toInt()+60);
                    puntos->setText(contpuntos);
                     QMessageBox::warning(this,"Sudoku Message","Felicitaciones ha finalizado el juego su puntaje es"+contpuntos);

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
    for(int i=0; i<1 ; i++)
    {
        aleatox=rand()%9;
        aleatoy=rand()%9;
        qDebug() << aleatox;
        qDebug() << aleatoy;

        if(numbersButton2[aleatox][aleatoy]->isEnabled()&& numbersButton2[aleatox][aleatoy]->text().toInt()==0){
          numbersButton2[aleatox][aleatoy]->setText(numbersButton[aleatox][aleatoy]->text());
          numbersButton1[aleatox][aleatoy]->setText(numbersButton[aleatox][aleatoy]->text());
          }else i--;

       }
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
    QMessageBox::warning(this,"Sudoku Message","El juego se guardo correctamente");

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






