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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QTablero
{
public:
    QAction *actionQuit_2;
    QAction *actionExit;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *QTablero)
    {
        if (QTablero->objectName().isEmpty())
            QTablero->setObjectName(QStringLiteral("QTablero"));
        QTablero->resize(711, 522);
        actionQuit_2 = new QAction(QTablero);
        actionQuit_2->setObjectName(QStringLiteral("actionQuit_2"));
        actionExit = new QAction(QTablero);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(QTablero);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        QTablero->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QTablero);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QTablero->setStatusBar(statusBar);
        menuBar = new QMenuBar(QTablero);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 711, 21));
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
        QTablero->setWindowTitle(QApplication::translate("QTablero", "QTablero", 0));
        actionQuit_2->setText(QApplication::translate("QTablero", "Quit", 0));
        actionExit->setText(QApplication::translate("QTablero", "Exit", 0));
        menuFile->setTitle(QApplication::translate("QTablero", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class QTablero: public Ui_QTablero {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTABLERO_H
