/********************************************************************************
** Form generated from reading UI file 'qtablero.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTABLERO_H
#define UI_QTABLERO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTablero
{
public:
    QAction *actionQuit_2;
    QAction *actionExit;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *celda1;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QWidget *gridLayoutWidget_3;
    QGridLayout *celda2;
    QWidget *gridLayoutWidget_4;
    QGridLayout *celda3;
    QWidget *gridLayoutWidget_5;
    QGridLayout *celda4;
    QWidget *gridLayoutWidget_6;
    QGridLayout *celda5;
    QWidget *gridLayoutWidget_7;
    QGridLayout *celda6;
    QWidget *gridLayoutWidget_8;
    QGridLayout *celda7;
    QWidget *gridLayoutWidget_9;
    QGridLayout *celda8;
    QWidget *gridLayoutWidget_10;
    QGridLayout *celda9;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QLCDNumber *lcdNumber;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *QTablero)
    {
        if (QTablero->objectName().isEmpty())
            QTablero->setObjectName(QStringLiteral("QTablero"));
        QTablero->resize(750, 522);
        QTablero->setAcceptDrops(true);
        actionQuit_2 = new QAction(QTablero);
        actionQuit_2->setObjectName(QStringLiteral("actionQuit_2"));
        actionExit = new QAction(QTablero);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(QTablero);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(20, 20, 151, 121));
        celda1 = new QGridLayout(gridLayoutWidget);
        celda1->setSpacing(6);
        celda1->setContentsMargins(11, 11, 11, 11);
        celda1->setObjectName(QStringLiteral("celda1"));
        celda1->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_2 = new QWidget(centralWidget);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(540, 0, 201, 71));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_3 = new QWidget(centralWidget);
        gridLayoutWidget_3->setObjectName(QStringLiteral("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(190, 20, 151, 121));
        celda2 = new QGridLayout(gridLayoutWidget_3);
        celda2->setSpacing(6);
        celda2->setContentsMargins(11, 11, 11, 11);
        celda2->setObjectName(QStringLiteral("celda2"));
        celda2->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_4 = new QWidget(centralWidget);
        gridLayoutWidget_4->setObjectName(QStringLiteral("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(360, 20, 151, 121));
        celda3 = new QGridLayout(gridLayoutWidget_4);
        celda3->setSpacing(6);
        celda3->setContentsMargins(11, 11, 11, 11);
        celda3->setObjectName(QStringLiteral("celda3"));
        celda3->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_5 = new QWidget(centralWidget);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(20, 160, 151, 121));
        celda4 = new QGridLayout(gridLayoutWidget_5);
        celda4->setSpacing(6);
        celda4->setContentsMargins(11, 11, 11, 11);
        celda4->setObjectName(QStringLiteral("celda4"));
        celda4->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_6 = new QWidget(centralWidget);
        gridLayoutWidget_6->setObjectName(QStringLiteral("gridLayoutWidget_6"));
        gridLayoutWidget_6->setGeometry(QRect(190, 160, 151, 121));
        celda5 = new QGridLayout(gridLayoutWidget_6);
        celda5->setSpacing(6);
        celda5->setContentsMargins(11, 11, 11, 11);
        celda5->setObjectName(QStringLiteral("celda5"));
        celda5->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_7 = new QWidget(centralWidget);
        gridLayoutWidget_7->setObjectName(QStringLiteral("gridLayoutWidget_7"));
        gridLayoutWidget_7->setGeometry(QRect(360, 160, 151, 121));
        celda6 = new QGridLayout(gridLayoutWidget_7);
        celda6->setSpacing(6);
        celda6->setContentsMargins(11, 11, 11, 11);
        celda6->setObjectName(QStringLiteral("celda6"));
        celda6->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_8 = new QWidget(centralWidget);
        gridLayoutWidget_8->setObjectName(QStringLiteral("gridLayoutWidget_8"));
        gridLayoutWidget_8->setGeometry(QRect(20, 300, 151, 121));
        celda7 = new QGridLayout(gridLayoutWidget_8);
        celda7->setSpacing(6);
        celda7->setContentsMargins(11, 11, 11, 11);
        celda7->setObjectName(QStringLiteral("celda7"));
        celda7->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_9 = new QWidget(centralWidget);
        gridLayoutWidget_9->setObjectName(QStringLiteral("gridLayoutWidget_9"));
        gridLayoutWidget_9->setGeometry(QRect(190, 300, 151, 121));
        celda8 = new QGridLayout(gridLayoutWidget_9);
        celda8->setSpacing(6);
        celda8->setContentsMargins(11, 11, 11, 11);
        celda8->setObjectName(QStringLiteral("celda8"));
        celda8->setContentsMargins(0, 0, 0, 0);
        gridLayoutWidget_10 = new QWidget(centralWidget);
        gridLayoutWidget_10->setObjectName(QStringLiteral("gridLayoutWidget_10"));
        gridLayoutWidget_10->setGeometry(QRect(360, 300, 151, 121));
        celda9 = new QGridLayout(gridLayoutWidget_10);
        celda9->setSpacing(6);
        celda9->setContentsMargins(11, 11, 11, 11);
        celda9->setObjectName(QStringLiteral("celda9"));
        celda9->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(20, 141, 491, 21));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(20, 281, 491, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(173, 20, 16, 401));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(343, 20, 16, 401));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        lcdNumber = new QLCDNumber(centralWidget);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(580, 80, 138, 28));
        QFont font;
        font.setBold(true);
        font.setUnderline(false);
        font.setWeight(75);
        lcdNumber->setFont(font);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(610, 140, 51, 51));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/visto1.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(50, 50));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(610, 210, 51, 51));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/ayuda.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon1);
        pushButton->setIconSize(QSize(50, 50));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(610, 290, 51, 51));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/guardar.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon2);
        pushButton_4->setIconSize(QSize(50, 50));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(610, 370, 51, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/exit.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_6->setIcon(icon3);
        pushButton_6->setIconSize(QSize(50, 50));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(540, 120, 161, 31));
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(540, 190, 161, 21));
        label_2->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(540, 270, 111, 20));
        label_3->setFont(font1);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(550, 353, 51, 20));
        label_4->setFont(font1);
        QTablero->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QTablero);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTablero->setStatusBar(statusBar);
        menuBar = new QMenuBar(QTablero);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 750, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        QTablero->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionExit);

        retranslateUi(QTablero);

        QMetaObject::connectSlotsByName(QTablero);
    } // setupUi

    void retranslateUi(QMainWindow *QTablero)
    {
        QTablero->setWindowTitle(QApplication::translate("QTablero", "Sudoku", 0));
        actionQuit_2->setText(QApplication::translate("QTablero", "Quit", 0));
        actionExit->setText(QApplication::translate("QTablero", "Exit", 0));
        pushButton_2->setText(QString());
        pushButton->setText(QString());
        pushButton_4->setText(QString());
        pushButton_6->setText(QString());
        label->setText(QApplication::translate("QTablero", "Verificar N\303\272mero Ingresado", 0));
        label_2->setText(QApplication::translate("QTablero", "Ayuda ", 0));
        label_3->setText(QApplication::translate("QTablero", "Guardar Partida", 0));
        label_4->setText(QApplication::translate("QTablero", "Salir", 0));
        menuFile->setTitle(QApplication::translate("QTablero", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class QTablero: public Ui_QTablero {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTABLERO_H
