#-------------------------------------------------
#
# Project created by QtCreator 2016-07-08T16:14:00
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PACKET
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    thread_test.cpp

HEADERS  += mainwindow.h \
    thread_test.h

FORMS    += mainwindow.ui
LIBS += -L/usr/include/pcap
LIBS += -lpcap
INCLUDEPATH += /usr/include/pcap
DEPENDPATH += /usr/include/pcap
