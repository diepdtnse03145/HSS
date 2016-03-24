TEMPLATE = app

QT += qml quick widgets androidextras

CONFIG += c++11

SOURCES += main.cpp \
    Engine/hssengine.cpp

HEADERS += \
    Engine/hssengine.h

RESOURCES += qml.qrc

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


