/********************************************************************************
** Form generated from reading UI file 'principal.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRINCIPAL_H
#define UI_PRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_principal
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *imagen;

    void setupUi(QDialog *principal)
    {
        if (principal->objectName().isEmpty())
            principal->setObjectName(QStringLiteral("principal"));
        principal->resize(400, 300);
        pushButton = new QPushButton(principal);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(30, 20, 91, 51));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setItalic(false);
        font.setUnderline(false);
        font.setWeight(75);
        font.setStrikeOut(false);
        pushButton->setFont(font);
        pushButton_2 = new QPushButton(principal);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 60, 111, 41));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_2->setFont(font1);
        pushButton_3 = new QPushButton(principal);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(270, 240, 121, 41));
        QFont font2;
        font2.setPointSize(15);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_3->setFont(font2);
        pushButton_4 = new QPushButton(principal);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 150, 141, 41));
        QFont font3;
        font3.setPointSize(11);
        font3.setBold(true);
        font3.setWeight(75);
        pushButton_4->setFont(font3);
        imagen = new QPushButton(principal);
        imagen->setObjectName(QStringLiteral("imagen"));
        imagen->setGeometry(QRect(-6, -8, 411, 311));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/ININ.png"), QSize(), QIcon::Normal, QIcon::Off);
        imagen->setIcon(icon);
        imagen->setIconSize(QSize(400, 300));
        imagen->raise();
        pushButton->raise();
        pushButton_2->raise();
        pushButton_3->raise();
        pushButton_4->raise();

        retranslateUi(principal);

        QMetaObject::connectSlotsByName(principal);
    } // setupUi

    void retranslateUi(QDialog *principal)
    {
        principal->setWindowTitle(QApplication::translate("principal", "sudoku", 0));
        pushButton->setText(QApplication::translate("principal", "Jugar", 0));
        pushButton_2->setText(QApplication::translate("principal", "Cargar Partida", 0));
        pushButton_3->setText(QApplication::translate("principal", "Salir", 0));
        pushButton_4->setText(QApplication::translate("principal", "Mejores Puntajes", 0));
        imagen->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class principal: public Ui_principal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRINCIPAL_H
