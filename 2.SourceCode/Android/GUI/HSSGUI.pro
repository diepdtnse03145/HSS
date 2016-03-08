TEMPLATE = app

QT += qml quick widgets

CONFIG += c++11

SOURCES += main.cpp \
    hssengine.cpp \
    ScreenManager/ScreenManager.cpp

RESOURCES += qml.qrc \
    img.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    hssengine.h \
    ScreenManager/ScreenDefine.h \
    ScreenManager/ScreenManager.h

