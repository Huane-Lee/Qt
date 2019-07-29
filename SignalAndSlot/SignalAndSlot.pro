#-------------------------------------------------
#
# Project created by QtCreator 2019-07-24T15:01:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SignalAndSlot
TEMPLATE = app


SOURCES += main.cpp\
        mymainwindow.cpp \
    subwindow.cpp

HEADERS  += mymainwindow.h \
    subwindow.h

FORMS    += mymainwindow.ui

CONFIG += c++11
