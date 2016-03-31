#include "engine.h"

Engine::Engine(QObject *parent) :
    QObject(parent),
    _javaMainAct{QAndroidJniObject::
                 callStaticObjectMethod("org/hss/hss/MyActivity",
                                        "getIns",
                                        "()Lorg/hss/hss/MyActivity;")
                 }
{

}

void Engine::MoeMoe()
{
    _javaMainAct.callMethod<void>("Moe");
}
