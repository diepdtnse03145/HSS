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
    _data{this},
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
    _engine.rootContext()->setContextProperty("Data", &_data);

    connect(this, &ConnectionBase::_connectToHostResult,
            this, &HSSEngine::handleConnectToHost);

    connect(this, &ConnectionBase::_ipChanged,
            [this] (QString ip) {
        _data.setDoorBellPic(QUrl::fromUserInput(QStringLiteral(R"(http://%1/door.jpg)").arg(ip)));
        showOnscreen(ip);
    });

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

void HSSEngine::endCall()
{
    _javaMainAct.callMethod<void>("endCall");
}

void HSSEngine::externalSpeaker()
{
    _javaMainAct.callMethod<void>("externalSpeaker");
}

void HSSEngine::internalSpeaker()
{
    _javaMainAct.callMethod<void>("internalSpeaker");
}

void HSSEngine::pi_requestLogin(const QString &username, const QString &pwd)
{
    m_loginingUsername = username;
    QString msg = QStringLiteral("pi_requestLogin %1 %2\n")
            .arg(stringToMsgArg(username))
            .arg(stringToMsgArg(pwd));
    _sendMsg(msg);
    //TEST
//    and_loginResult(true);
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
    //TEST
//    and_enableDetectDoorResult(false, false);

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
    QString msg = QStringLiteral("pi_requestCameraInfo\n");
    _sendMsg(msg);
    //TEST
//        QString res = "[\n"
//                      "    {\"name\":\"Camera\", \"url\":\"http://doc.qt.io/qt-5/qjsondocument.html\"},\n"
//                      "    {\"name\":\"Camera\", \"url\":\"http://doc.qt.io/qt-5/qjsondocument.html\"},\n"
//                      "    {\"name\":\"Camera\", \"url\":\"http://doc.qt.io/qt-5/qjsondocument.html\"}\n"
//                      "]";
//        and_returnCameraInfo(res);
}

void HSSEngine::pi_requestActivityLog()
{
    QString msg = QStringLiteral("pi_requestActivityLog\n");
    _sendMsg(msg);
}

void HSSEngine::pi_deleteActitvityLog()
{
    QString msg = QStringLiteral("pi_deleteActitvityLog\n");
    _sendMsg(msg);
}

void HSSEngine::pi_requestCallAdd()
{
    QString msg = QStringLiteral("pi_requestCallAdd\n");
    _sendMsg(msg);
}

void HSSEngine::pi_requestSettingStt()
{
    QString msg = QStringLiteral("pi_requestSettingStt\n");
    _sendMsg(msg);
}

void HSSEngine::_hss_recvMsg(const QString &msg)
{
    auto v = msg.split(QRegExp{R"mm(\s+)mm"}, QString::SkipEmptyParts);

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
        int and_returnMotionStatus_arg1 = msgArgToInt(v.at(1));
        and_returnMotionStatus(and_returnMotionStatus_arg1);
    }

    if (v.at(0) == "and_returnBellStatus") {
        int and_returnBellStatus_arg1 = msgArgToInt(v.at(1));
        and_returnBellStatus(and_returnBellStatus_arg1);
    }

    if (v.at(0) == "and_returnCameraInfo") {
        QString and_returnCameraInfo_arg1 = msgArgToString(v.at(1));
        and_returnCameraInfo(and_returnCameraInfo_arg1);
    }

    if (v.at(0) == "and_deleteActitvityLogResult") {
        bool and_deleteActitvityLogResult_arg1 = msgArgToBool(v.at(1));
        and_deleteActitvityLogResult(and_deleteActitvityLogResult_arg1);
    }

    if (v.at(0) == "and_returnActivityLog") {
        QString and_returnActivityLog_arg1 = msgArgToString(v.at(1));
        and_returnActivityLog(and_returnActivityLog_arg1);
    }

    if (v.at(0) == "and_returnCallAdd") {
        QString and_returnCallAdd_arg1 = msgArgToString(v.at(1));
        and_returnCallAdd(and_returnCallAdd_arg1);
    }

    if (v.at(0) == "and_returnSettingStt") {
        bool and_returnSettingStt_arg1 = msgArgToBool(v.at(1));
        bool and_returnSettingStt_arg2 = msgArgToBool(v.at(2));
        bool and_returnSettingStt_arg3 = msgArgToBool(v.at(3));
        and_returnSettingStt(and_returnSettingStt_arg1,
                             and_returnSettingStt_arg2,
                             and_returnSettingStt_arg3);
    }

    if (v.at(0) == "and_enableDetectMotionResult") {
        bool and_enableDetectMotionResult_arg1 = msgArgToBool(v.at(1));
        and_enableDetectMotionResult(and_enableDetectMotionResult_arg1);
    }

    if (v.at(0) == "and_enableDetectDoorResult") {
        bool and_enableDetectDoorResult_arg1 = msgArgToBool(v.at(1));
        bool and_enableDetectDoorResult_arg2 = msgArgToBool(v.at(2));
        and_enableDetectDoorResult(and_enableDetectDoorResult_arg1,
                                   and_enableDetectDoorResult_arg2);
    }

    if (v.at(0) == "and_enableDoorBellResult") {
        bool and_enableDoorBellResult_arg1 = msgArgToBool(v.at(1));
        and_enableDoorBellResult(and_enableDoorBellResult_arg1);
    }
}

void HSSEngine::startCall(const QString &address)
{
    auto _add = QAndroidJniObject::fromString(address);
    _javaMainAct.callMethod<void>("call", "(Ljava/lang/String;)V", _add.object<jstring>());

}

void HSSEngine::and_loginResult(bool result)
{
    if (result) {
        showOnscreen("Login Sucessfull!");
        _scrMng.setIsLogin(true);
        _data.setUsername(m_loginingUsername);
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

    _data.setIsEnableDetectMotion(result);
}

void HSSEngine::and_enableDetectDoorResult(bool result, bool isDoorClosed)
{
    if(result) {
        showOnscreen("Door Detector Enabled!");
    } else {
        showOnscreen("Door Detector Disabled!");
    }

    if(isDoorClosed) {
        showOnscreen("Door is being closed!");
    } else {
        showOnscreen("Door is being opened!");
    }

    _data.setIsEnableDetectDoor(result);
}

void HSSEngine::and_enableDoorBellResult(bool result)
{
    if(result) {
        showOnscreen("Door Bell Enabled!");
    } else {
        showOnscreen("Door Bell Disabled!");
    }

    _data.setIsEnableDoorBell(result);
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

void HSSEngine::and_returnCameraInfo(const QString &result)
{
    auto res_arr = QJsonDocument::fromJson(result.toUtf8()).array();

    for (const auto& ite : res_arr) {
        _cameraModel.add(ite.toObject().value("name").toString(),
                         ite.toObject().value("url").toString());
    }

}

void HSSEngine::and_returnActivityLog(const QString &log)
{
    auto res_arr = QJsonDocument::fromJson(log.toUtf8()).array();

    for (const auto& ite : res_arr) {
        _activityModel.add(ite.toObject().value("timestamp").toString(),
                           ite.toObject().value("activity").toString());
    }
}

void HSSEngine::and_deleteActitvityLogResult(bool result)
{
    if (result) {
        showOnscreen("Activity log deleted!");
//        pi_requestActivityLog();
    } else {
        showOnscreen("Delete Activity log failed!");
    }
}

void HSSEngine::and_returnCallAdd(const QString &address)
{
    startCall(address);
}

void HSSEngine::and_returnSettingStt(bool dtMotion, bool dtDoor, bool bell)
{
    _data.setIsEnableDetectMotion(dtMotion);
    _data.setIsEnableDetectDoor(dtDoor);
    _data.setIsEnableDoorBell(bell);
   _scrMng.toSettingScr();

}

void HSSEngine::handleConnectToHost(bool result)
{
    if (result) {
//        showOnscreen("Connected");
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
