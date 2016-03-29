#include "hssengine.h"
#include "Connection/rpc_pr.h"
#include <QtQml>
#include <QtAndroidExtras>

HSSEngine* ENGINE = nullptr;

HSSEngine::HSSEngine(QObject *parent):
    ConnectionBase{parent},
    _scrMng{this},
    _cameraModel{this},
    _activityModel{this},
    _javaMainAct{QAndroidJniObject::
                 callStaticObjectMethod("org/hss/hss/MyActivity",
                                        "getIns",
                                        "()Lorg/hss/hss/MyActivity;")
                 }
{
    _engine.rootContext()->setContextProperty("ScreenManager", &_scrMng);
    _engine.rootContext()->setContextProperty("Engine", this);
    _engine.rootContext()->setContextProperty("CameraModel", &_cameraModel);
    _engine.rootContext()->setContextProperty("ActivityModel", &_activityModel);

    connect(this, &ConnectionBase::_connectToHostResult,
            this, &HSSEngine::handleConnectToHost);
    ENGINE = this;
}

void HSSEngine::run()
{
    _engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    QObject::connect(&_scrMng,&ScreenManager::currentScreenChanged,[this](QUrl source){
        QMetaObject::invokeMethod(_engine.rootObjects().at(0), "loadScreen",
                                  Q_ARG(QVariant, source));
    });
    _scrMng.run();

}

void HSSEngine::callHandleBack()
{
    QMetaObject::invokeMethod(_engine.rootObjects().at(0), "backKeyCaptured");
}

void HSSEngine::resumeToLogin()
{
    _scrMng.setIsLogin(false);
}

void HSSEngine::pi_requestLogin(const QString &username, const QString &pwd)
{
    //    QString msg = QStringLiteral("pi_requestLogin %1 %2\n")
    //            .arg(stringToMsgArg(username))
    //            .arg(stringToMsgArg(pwd));
    //    _sendMsg(msg);
    and_loginResult(true);
}

void HSSEngine::pi_changePassword(const QString &username, const QString &oldpwd, const QString &newpwd)
{
    QString msg = QStringLiteral("pi_changePassword %1 %2 %3\n")
            .arg(stringToMsgArg(username))
            .arg(stringToMsgArg(oldpwd))
            .arg(stringToMsgArg(newpwd));
    _sendMsg(msg);
}

void HSSEngine::pi_enableDetectMotion(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDetectMotion %1\n")
            .arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void HSSEngine::pi_enableDetectDoor(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDetectDoor %1\n")
            .arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void HSSEngine::pi_enableDoorBell(const bool &enable)
{
    QString msg = QStringLiteral("pi_enableDoorBell %1\n")
            .arg(boolToMsgArg(enable));
    _sendMsg(msg);
}

void HSSEngine::pi_requestDoorStatus()
{
    QString msg = QStringLiteral("pi_requestDoorStatus\n");
    _sendMsg(msg);
}

void HSSEngine::pi_requestMotionStatus()
{
    QString msg = QStringLiteral("pi_requestMotionStatus\n");
    _sendMsg(msg);
}

void HSSEngine::pi_requestBellStatus()
{
    QString msg = QStringLiteral("pi_requestBellStatus\n");
    _sendMsg(msg);
}

void HSSEngine::pi_requestCameraInfo()
{
    //    QString msg = QStringLiteral("pi_requestCameraInfo\n");
    //    _sendMsg(msg);
    _cameraModel.add("absd", "dasfsdg");
    _cameraModel.add("absd", "dasfsdg");
    _cameraModel.add("absd", "dasfsdg");
    _cameraModel.add("absd", "dasfsdg");
    _cameraModel.add("absd", "dasfsdg");

}

void HSSEngine::_hss_recvMsg(const QString &msg)
{
    auto v = msg.split(QRegExp{R"mm(\s+)mm"}, QString::SkipEmptyParts);

    if (v.at(0) == "and_changePwResult") {
        bool and_changePwResult_arg1 = msgArgToBool(v.at(1));
        and_changePwResult(and_changePwResult_arg1);
    }

    if (v.at(0) == "and_loginResult") {
        bool and_loginResult_arg1 = msgArgToBool(v.at(1));
        and_loginResult(and_loginResult_arg1);
    }

    if (v.at(0) == "and_changePwResult") {
        bool and_changePwResult_arg1 = msgArgToBool(v.at(1));
        and_changePwResult(and_changePwResult_arg1);
    }

    if (v.at(0) == "and_returnDoorStatus") {
        int and_returnDoorStatus_arg1 = msgArgToInt(v.at(1));
        and_returnDoorStatus(and_returnDoorStatus_arg1);
    }

    if (v.at(0) == "and_returnMotionStatus") {
        bool and_returnMotionStatus_arg1 = msgArgToInt(v.at(1));
        and_returnMotionStatus(and_returnMotionStatus_arg1);
    }

    if (v.at(0) == "and_returnBellStatus") {
        bool and_returnBellStatus_arg1 = msgArgToInt(v.at(1));
        and_returnBellStatus(and_returnBellStatus_arg1);
    }

    if (v.at(0) == "and_appendCameraInfo") {
        QString and_appendCameraInfo_arg1 = msgArgToString(v.at(1));
        QString and_appendCameraInfo_arg2 = msgArgToString(v.at(2));
        and_appendCameraInfo(and_appendCameraInfo_arg1,
                             and_appendCameraInfo_arg2);
    }

}

void HSSEngine::and_loginResult(bool result)
{
    if (result) {
        showOnscreen("Login Sucessfull!");
        _scrMng.setIsLogin(true);
    } else {
        showOnscreen("Login Failed!");
    }
}

void HSSEngine::and_changePwResult(bool result)
{
    if (result) {
        showOnscreen("Password changed!");
        _scrMng.toLoginScr();
    } else {
        showOnscreen("Password unchanged!");
    }
}

void HSSEngine::and_enableDetectMotionResult(bool result)
{
    if(result) {
        showOnscreen("Motion Detector Enabled!");
    } else {
        showOnscreen("Motion Detector Disabled!");
    }
}

void HSSEngine::and_enableDetectDoorResult(bool result)
{
    if(result) {
        showOnscreen("Door Detector Enabled!");
    } else {
        showOnscreen("Door Detector Disabled!");
    }
}

void HSSEngine::and_enableDoorBellResult(bool result)
{
    if(result) {
        showOnscreen("Door Bell Enabled!");
    } else {
        showOnscreen("Door Bell Disabled!");
    }
}

void HSSEngine::and_returnDoorStatus(int status)
{
    Q_UNUSED(status)
}

void HSSEngine::and_returnMotionStatus(int status)
{
    Q_UNUSED(status)
}

void HSSEngine::and_returnBellStatus(int status)
{
    Q_UNUSED(status)
}

void HSSEngine::and_appendCameraInfo(const QString &cameraName,
                                     const QString &cameraUrl)
{

}

void HSSEngine::handleConnectToHost(bool result)
{
    if (result) {
        showOnscreen("Connected");
    } else {
        showOnscreen("Connect failed!");
    }
}

void HSSEngine::showOnscreen(const QString &msg)
{
    QAndroidJniObject javaMsg = QAndroidJniObject::fromString(msg);
    _javaMainAct.callMethod<void>("showToast",
                                  "(Ljava/lang/String;)V",
                                  javaMsg.object<jstring>()
                                  );
}

void HSSEngine::toHome()
{
    _javaMainAct.callMethod<void>("toHome");
}

void registerNativeMethods() {
    JNINativeMethod methods[] {
        {"toLoginScr", "()V",reinterpret_cast<void *>(ENGINE_toLoginScr)}
    };

    QAndroidJniObject javaClass = QAndroidJniObject::
            callStaticObjectMethod("org/hss/hss/MyActivity",
                                   "getIns",
                                   "()Lorg/hss/hss/MyActivity;");

    QAndroidJniEnvironment env;
    jclass objectClass = env->GetObjectClass(javaClass.object<jobject>());
    env->RegisterNatives(objectClass,
                         methods,
                         sizeof(methods) / sizeof(methods[0]));
    env->DeleteLocalRef(objectClass);
}

void ENGINE_toLoginScr(JNIEnv *env, jobject thiz)
{
    Q_UNUSED(env)
    Q_UNUSED(thiz)
    if (ENGINE) {
        ENGINE->resumeToLogin();
    }
}
