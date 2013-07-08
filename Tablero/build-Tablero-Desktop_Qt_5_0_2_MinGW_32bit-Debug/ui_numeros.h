/********************************************************************************
** Form generated from reading UI file 'numeros.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NUMEROS_H
#define UI_NUMEROS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_Numeros
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *lineEdit;

    void setupUi(QDialog *Numeros)
    {
        if (Numeros->objectName().isEmpty())
            Numeros->setObjectName(QStringLiteral("Numeros"));
        Numeros->resize(189, 132);
        buttonBox = new QDialogButtonBox(Numeros);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(20, 80, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Numeros);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 101, 16));
        lineEdit = new QLineEdit(Numeros);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(40, 40, 113, 20));

        retranslateUi(Numeros);
        QObject::connect(buttonBox, SIGNAL(accepted()), Numeros, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Numeros, SLOT(reject()));

        QMetaObject::connectSlotsByName(Numeros);
    } // setupUi

    void retranslateUi(QDialog *Numeros)
    {
        Numeros->setWindowTitle(QApplication::translate("Numeros", "Dialog", 0));
        label->setText(QApplication::translate("Numeros", "Ingrese el n\303\272mero:", 0));
    } // retranslateUi

};

namespace Ui {
    class Numeros: public Ui_Numeros {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NUMEROS_H
