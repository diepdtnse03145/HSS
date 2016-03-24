#ifndef HSSENGINE_H
#define HSSENGINE_H

#include <QQmlApplicationEngine>
#include <QAndroidJniObject>

class HSSEngine : QObject
{
    Q_OBJECT
public:
    HSSEngine(QObject* parent = 0);
    void run();

public slots:
    void showOnscreen(const QString& msg);

private:
    QQmlApplicationEngine _engine;
    QAndroidJniObject _javaMainAct;

    void registerNativeMethods();
};

#endif // HSSENGINE_H
