/********************************************************************************
** Form generated from reading UI file 'hilo1.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HILO1_H
#define UI_HILO1_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hilo1
{
public:
    QLCDNumber *lcdNumber;

    void setupUi(QWidget *hilo1)
    {
        if (hilo1->objectName().isEmpty())
            hilo1->setObjectName(QStringLiteral("hilo1"));
        hilo1->resize(110, 21);
        lcdNumber = new QLCDNumber(hilo1);
        lcdNumber->setObjectName(QStringLiteral("lcdNumber"));
        lcdNumber->setGeometry(QRect(0, 0, 111, 21));

        retranslateUi(hilo1);

        QMetaObject::connectSlotsByName(hilo1);
    } // setupUi

    void retranslateUi(QWidget *hilo1)
    {
        hilo1->setWindowTitle(QApplication::translate("hilo1", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class hilo1: public Ui_hilo1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HILO1_H
