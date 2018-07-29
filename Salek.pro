#-------------------------------------------------
#
# Project created by QtCreator 2018-07-24T22:22:16
#
#-------------------------------------------------

QT       += core gui

QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Salek
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    frmnew.cpp \
    frmupdate.cpp

HEADERS  += mainwindow.h \
    frmnew.h \
    frmupdate.h

FORMS    += mainwindow.ui \
    frmnew.ui \
    frmupdate.ui
