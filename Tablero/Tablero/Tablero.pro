#-------------------------------------------------
#
# Project created by QtCreator 2013-06-04T20:04:46
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tablero
TEMPLATE = app


SOURCES += main.cpp\
    nivel.cpp \
    qtablero.cpp \
    principal.cpp \
    hilo1.cpp \
    numeros.cpp

HEADERS  += \
    nivel.h \
    qtablero.h \
    principal.h \
    hilo1.h \
    numeros.h

FORMS    += \
    nivel.ui \
    qtablero.ui \
    principal.ui \
    hilo1.ui \
    numeros.ui

RESOURCES += \
    images.qrc
