#-------------------------------------------------
#
# Project created by QtCreator 2016-01-11T00:55:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = Plotting
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    point.cpp \
    graph.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    point.h \
    graph.h

FORMS    += mainwindow.ui
