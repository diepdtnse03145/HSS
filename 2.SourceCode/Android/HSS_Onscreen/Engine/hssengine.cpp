#include "hssengine.h"
#include <QtQml>

HSSEngine::HSSEngine(QObject *parent):
    QObject{parent},
    _javaMainAct{QAndroidJniObject::
                 callStaticObjectMethod("org/hss/hss/MyActivity",
                                        "getIns",
                                        "()Lorg/hss/hss/MyActivity;")
                 }
{
    _engine.rootContext()->setContextProperty("Engine", this);
}

void HSSEngine::run()
{
    _engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
}

void HSSEngine::showOnscreen(const QString &msg)
{
    qDebug()<<__FUNCTION__;
    QAndroidJniObject javaMsg = QAndroidJniObject::fromString(msg);
    _javaMainAct.callMethod<void>("showToast",
                                  "(Ljava/lang/String;)V",
                                  javaMsg.object<jstring>()
                                  );

}

void HSSEngine::registerNativeMethods()
{

}
