QT += core network
QT -= gui

CONFIG += c++11

TARGET = HSSConnection
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    Connection/connectionbase.cpp \
    Engine/piengine.cpp \
    rpc_pr.cpp

HEADERS += \
    Connection/connectionbase.h \
    Engine/piengine.h \
    rpc_pr.h
