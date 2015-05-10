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
    MyCustomWidget.cpp \
#    shapes.cpp \
    mylineshape.cpp \
    myrectangleshape.cpp \
    myellipseshape.cpp \
    mypenshape.cpp

CONFIG += c++11

HEADERS  += mainwindow.h \
    MyCustomWidget.h \
    shapes.h \
    mylineshape.h \
    myrectangleshape.h \
    myellipseshape.h \
    mypenshape.h

FORMS    += mainwindow.ui

RESOURCES += \
    paintResource.qrc
