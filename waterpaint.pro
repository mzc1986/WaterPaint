#-------------------------------------------------
#
# Project created by QtCreator 2015-04-10T21:01:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = mdiSand
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    MyCustomWidget.cpp

HEADERS  += mainwindow.h \
    MyCustomWidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    paintResource.qrc
