#include "engine.h"

Engine::Engine(QObject *parent) :
    QObject(parent),
    _javaMainAct{QAndroidJniObject::
                 callStaticObjectMethod("org/hss/hss/MyActivity",
                                        "getIns",
                                        "()Lorg/hss/hss/MyActivity;")
                 },
    _calling{false}
{

}

void Engine::MoeMoe()
{
    auto _add = QAndroidJniObject::fromString("sip:diepdtn@sip.linphone.org");

    _calling =! _calling;
    qDebug()<<__FUNCTION__<<_calling;

    if (!_calling) {
        _javaMainAct.callMethod<void>("call", "(Ljava/lang/String;)V", _add.object<jstring>());
    } else {
        _javaMainAct.callMethod<void>("endCall");
    }
//    String destinationSipAddress = "sip:diepdtn@sip.linphone.org";
}
