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
    Q_PROPERTY(QString username MEMBER m_username NOTIFY usernameChanged)
    Q_PROPERTY(QString cameraUrl READ cameraUrl WRITE setCameraUrl NOTIFY cameraUrlChanged)

public:
    HSSEngine(QObject* parent = 0);
    void run();

    QString cameraUrl() const;
    void setCameraUrl(const QString &cameraUrl);

signals:
    void usernameChanged();
    void cameraUrlChanged();

public slots:
    void showOnscreen(const QString &msg);
    void toHome();
    void callHandleBack();
    void resumeToLogin();
    void endCall();

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
    void pi_requestCallAdd();

private:
    void _hss_recvMsg(const QString &msg) override;
    void startCall(const QString& address);

    void and_loginResult(bool result);
    void and_changePwResult(bool result);
    void and_enableDetectMotionResult(bool result);
    void and_enableDetectDoorResult(bool result);
    void and_enableDoorBellResult(bool result);
    void and_returnDoorStatus(int status);
    void and_returnMotionStatus(int status);
    void and_returnBellStatus(int status);
    void and_returnCameraInfo(const QString& result);
    void and_returnActivityLog(const QString& log);
    void and_returnCallAdd(const QString& address);

private slots:
    void handleConnectToHost(bool result);

private:
    QQmlApplicationEngine _engine;
    ScreenManager _scrMng;
    CameraListModel _cameraModel;
    ActivityListModel _activityModel;
    QAndroidJniObject _javaMainAct;
    QString m_username;
    QString m_loginingUsername;
    QString m_cameraUrl;
};

extern HSSEngine* ENGINE;
void ENGINE_toLoginScr(JNIEnv *env, jobject thiz);
void registerNativeMethods();

#endif // HSSENGINE_H
