TEMPLATE = app

QT += qml quick widgets androidextras

CONFIG += c++11

HEADERS += \
    ScreenManager/ScreenDefine.h \
    ScreenManager/ScreenManager.h \
    Engine/hssengine.h \
    Connection/connectionbase.h \
    Connection/rpc_pr.h

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

DISTFILES += \
    android/AndroidManifest.xml \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/gradlew \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew.bat \
    android/java/org/hss/hss/MyActivity.java \
    android/java/org/hss/hss/MyService.java

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android