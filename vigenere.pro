#-------------------------------------------------
#
# Project created by QtCreator 2015-02-19T20:06:09
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = vigenere
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    vigenere.cpp \
    form.cpp


HEADERS  += mainwindow.h \
    vigenere.h \
    form.h

FORMS    += mainwindow.ui \
    form.ui
