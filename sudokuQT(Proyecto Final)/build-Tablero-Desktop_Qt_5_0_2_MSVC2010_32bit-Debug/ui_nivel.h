/********************************************************************************
** Form generated from reading UI file 'nivel.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NIVEL_H
#define UI_NIVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_nivel
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QRadioButton *facil;
    QRadioButton *medio;
    QRadioButton *dificil;
    QLabel *label;
    QLineEdit *nombretexto;
    QLabel *label_2;

    void setupUi(QDialog *nivel)
    {
        if (nivel->objectName().isEmpty())
            nivel->setObjectName(QStringLiteral("nivel"));
        nivel->resize(400, 295);
        pushButton = new QPushButton(nivel);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(50, 210, 60, 60));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/visto.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(60, 60));
        pushButton_2 = new QPushButton(nivel);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 210, 60, 60));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/x.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon1);
        pushButton_2->setIconSize(QSize(60, 60));
        facil = new QRadioButton(nivel);
        facil->setObjectName(QStringLiteral("facil"));
        facil->setGeometry(QRect(200, 120, 82, 17));
        facil->setChecked(true);
        medio = new QRadioButton(nivel);
        medio->setObjectName(QStringLiteral("medio"));
        medio->setGeometry(QRect(200, 150, 82, 17));
        dificil = new QRadioButton(nivel);
        dificil->setObjectName(QStringLiteral("dificil"));
        dificil->setGeometry(QRect(200, 180, 82, 17));
        label = new QLabel(nivel);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 60, 71, 21));
        nombretexto = new QLineEdit(nivel);
        nombretexto->setObjectName(QStringLiteral("nombretexto"));
        nombretexto->setGeometry(QRect(160, 60, 191, 20));
        label_2 = new QLabel(nivel);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 122, 101, 21));

        retranslateUi(nivel);

        QMetaObject::connectSlotsByName(nivel);
    } // setupUi

    void retranslateUi(QDialog *nivel)
    {
        nivel->setWindowTitle(QApplication::translate("nivel", "Juego Nuevo", 0));
        pushButton->setText(QString());
        pushButton_2->setText(QString());
        facil->setText(QApplication::translate("nivel", "facil", 0));
        medio->setText(QApplication::translate("nivel", "medio", 0));
        dificil->setText(QApplication::translate("nivel", "dificikl", 0));
        label->setText(QApplication::translate("nivel", "<html><head/><body><p><span style=\" font-size:12pt;\">Jugador:</span></p></body></html>", 0));
        nombretexto->setText(QApplication::translate("nivel", "nombre del jugador", 0));
        label_2->setText(QApplication::translate("nivel", "<html><head/><body><p><span style=\" font-size:12pt;\">Dificultad</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class nivel: public Ui_nivel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NIVEL_H
