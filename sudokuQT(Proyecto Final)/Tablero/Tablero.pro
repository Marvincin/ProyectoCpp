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
    principal.cpp

HEADERS  += \
    nivel.h \
    qtablero.h \
    principal.h

FORMS    += \
    nivel.ui \
    qtablero.ui \
    principal.ui

RESOURCES += \
    images.qrc
