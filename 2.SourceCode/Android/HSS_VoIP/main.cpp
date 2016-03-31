#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>

#include "engine.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Engine e;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("engine", &e);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
