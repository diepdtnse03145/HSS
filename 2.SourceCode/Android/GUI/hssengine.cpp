#include "hssengine.h"
#include <QtQml>

HSSEngine::HSSEngine()
{
    _engine.rootContext()->setContextProperty("ScreenManager",&_scrMng);
}

void HSSEngine::run()
{
    _scrMng.run();
    _engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject::connect(&_scrMng,&ScreenManager::currentScreenChanged,[this](QUrl source){
        QMetaObject::invokeMethod(_engine.rootObjects().at(0), "loadScreen",
                                  Q_ARG(QVariant, source));
    });
}
