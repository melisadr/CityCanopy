#-------------------------------------------------
#
# Project created by QtCreator 2015-04-06T13:28:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CityCanopy
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    topodatamanager.cpp \
    figure.cpp \
    topofigure.cpp \
    urbandatamanager.cpp \
    urbanfigure.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    datamanager.h \
    topodatamanager.h \
    figure.h \
    topofigure.h \
    urbandatamanager.h \
    urbanfigure.h

FORMS    +=
