#-------------------------------------------------
#
# Project created by QtCreator 2016-02-26T11:30:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hw8
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    newgameboard.cpp \
    mywidget.cpp

HEADERS  += mainwindow.h \
    newgameboard.h \
    mywidget.h

FORMS    += mainwindow.ui \
    newgameboard.ui

DISTFILES +=

RESOURCES += \
    picture.qrc
