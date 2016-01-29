QT += core websockets
QT -= gui

TARGET = BlitServer
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += src/main.cpp \
    src/Server.cpp \
    src/Client.cpp \
    src/Game.cpp

HEADERS += \
    src/Server.h \
    src/Client.h \
    src/Game.h

