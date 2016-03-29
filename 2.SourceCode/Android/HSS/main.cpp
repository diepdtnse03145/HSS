#include "Engine/hssengine.h"
#include "Engine/hsseventfilter.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    registerNativeMethods();
    HSSEngine engine;
    HSSEventFilter filter;
    QObject::connect(&filter, &HSSEventFilter::backKeyCaptured,
                     &engine, &HSSEngine::callHandleBack);    
    QObject::connect(&filter, &HSSEventFilter::applicationActivateCaptured,
                     &engine, &HSSEngine::resumeToLogin);

    app.installEventFilter(&filter);
    engine.run();
    return app.exec();
}

