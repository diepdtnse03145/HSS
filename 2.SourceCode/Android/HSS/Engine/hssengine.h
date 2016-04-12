#ifndef HSSENGINE_H
#define HSSENGINE_H

#include "ScreenManager/ScreenManager.h"
#include "ScreenManager/cameralistmodel.h"
#include "ScreenManager/activitylistmodel.h"
#include "Connection/connectionbase.h"
#include "hssdata.h"

#include <QQmlApplicationEngine>
#include <QAndroidJniObject>

class HSSEngine : public ConnectionBase
{
    Q_OBJECT

public:
    HSSEngine(QObject* parent = 0);
    void run();

public slots:
    void showOnscreen(const QString &msg);
    void toHome();
    void callHandleBack();
    void resumeToLogin();
    void endCall();
    void externalSpeaker();
    void internalSpeaker();

    void pi_requestLogin(const QString& username,
                         const QString& pwd);
    void pi_changePassword(const QString& username,
                           const QString& oldpwd,
                           const QString& newpwd);
    void pi_enableDetectMotion(const bool& enable);
    void pi_enableDetectDoor(const bool& enable);
    void pi_enableDoorBell(const bool& enable);
    void pi_requestDoorStatus();
    void pi_requestMotionStatus();
    void pi_requestBellStatus();
    void pi_requestCameraInfo();
    void pi_requestActivityLog();
    void pi_deleteActitvityLog();
    void pi_requestCallAdd();
    void pi_requestSettingStt();

private:
    void _hss_recvMsg(const QString &msg) override;
    void startCall(const QString& address);

    void and_loginResult(bool result);
    void and_changePwResult(bool result);
    void and_enableDetectMotionResult(bool result);
    void and_enableDetectDoorResult(bool result, bool isDoorClosed);
    void and_enableDoorBellResult(bool result);
    void and_returnDoorStatus(int status);
    void and_returnMotionStatus(int status);
    void and_returnBellStatus(int status);
    void and_returnCameraInfo(const QString& result);
    void and_returnActivityLog(const QString& log);
    void and_deleteActitvityLogResult(bool result);
    void and_returnCallAdd(const QString& address);
    void and_returnSettingStt(bool dtMotion, bool dtDoor, bool bell);

private slots:
    void handleConnectToHost(bool result);

private:
    QQmlApplicationEngine _engine;
    ScreenManager _scrMng;
    CameraListModel _cameraModel;
    ActivityListModel _activityModel;
    HSSData _data;
    QAndroidJniObject _javaMainAct;
    QString m_loginingUsername;
};

extern HSSEngine* ENGINE;
void ENGINE_toLoginScr(JNIEnv *env, jobject thiz);
void registerNativeMethods();

#endif // HSSENGINE_H
