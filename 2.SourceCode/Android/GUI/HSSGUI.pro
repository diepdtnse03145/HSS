TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    ScreenManager/ScreenManager.cpp \
    Engine/hssengine.cpp \
    Connection/connectionbase.cpp \
    Connection/rpc_pr.cpp

RESOURCES += qml.qrc \
    img.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ScreenManager/ScreenDefine.h \
    ScreenManager/ScreenManager.h \
    Engine/hssengine.h \
    Connection/connectionbase.h \
    Connection/rpc_pr.h

