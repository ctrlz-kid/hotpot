#-------------------------------------------------
#
# Project created by QtCreator 2019-08-15T22:39:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    network/hpudpservice.cpp \
    network/hpmessgerecorder.cpp \
    test.cpp \
    theme.cpp \
    theme_p.cpp

HEADERS  += mainwindow.h \
    network/hpudpservice.h \
    network/hpmessgerecorder.h \
    test.h \
    theme.h \
    theme_p.h

FORMS    += mainwindow.ui

#ini path
DEPENDPATH += ../ini
