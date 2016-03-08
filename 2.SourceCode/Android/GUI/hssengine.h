#ifndef HSSENGINE_H
#define HSSENGINE_H

#include "ScreenManager/ScreenManager.h"

#include <QQmlApplicationEngine>

class HSSEngine
{
public:
    HSSEngine();
    void run();

private:
    QQmlApplicationEngine _engine;
    ScreenManager _scrMng;
};

#endif // HSSENGINE_H
