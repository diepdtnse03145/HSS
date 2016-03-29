#ifndef HSSENGINE_H
#define HSSENGINE_H

#include "ScreenManager/ScreenManager.h"
#include "ScreenManager/cameralistmodel.h"
#include "ScreenManager/activitylistmodel.h"
#include "Connection/connectionbase.h"
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

private:
    void _hss_recvMsg(const QString &msg) override;

    void and_loginResult(bool result);
    void and_changePwResult(bool result);
    void and_enableDetectMotionResult(bool result);
    void and_enableDetectDoorResult(bool result);
    void and_enableDoorBellResult(bool result);
    void and_returnDoorStatus(int status);
    void and_returnMotionStatus(int status);
    void and_returnBellStatus(int status);
    void and_appendCameraInfo(const QString& cameraName,
                              const QString& cameraUrl);

private slots:
    void handleConnectToHost(bool result);

private:
    QQmlApplicationEngine _engine;
    ScreenManager _scrMng;
    CameraListModel _cameraModel;
    ActivityListModel _activityModel;
    QAndroidJniObject _javaMainAct;
};

extern HSSEngine* ENGINE;
void ENGINE_toLoginScr(JNIEnv *env, jobject thiz);
void registerNativeMethods();

#endif // HSSENGINE_H
