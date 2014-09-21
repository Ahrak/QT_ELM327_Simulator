#-------------------------------------------------
#
# Project created by QtCreator 2014-09-19T15:07:45
#
#-------------------------------------------------

QT       += core gui serialport network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtOBDSimulator
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    udpreceiver.cpp

HEADERS  += mainwindow.h \
    udpreceiver.h \
    OutGauge.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    .gitignore \
    README.md
