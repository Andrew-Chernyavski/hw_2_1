QT       += core

QT       -= gui

TARGET = task1
CONFIG   += console
CONFIG   += qtestlib
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    main.cpp \
    PC.cpp \
    Web.cpp

HEADERS += \
    OS.h \
    PC.h \
    Web.h \
    Test.h
