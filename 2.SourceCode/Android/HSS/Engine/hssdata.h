#ifndef HSSDATA_H
#define HSSDATA_H

#include <QObject>

class HSSData : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString username READ username WRITE setUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString cameraUrl READ cameraUrl WRITE setCameraUrl NOTIFY cameraUrlChanged)
    Q_PROPERTY(bool isEnableDetectMotion READ isEnableDetectMotion WRITE setIsEnableDetectMotion NOTIFY isEnableDetectMotionChanged)
    Q_PROPERTY(bool isEnableDetectDoor READ isEnableDetectDoor WRITE setIsEnableDetectDoor NOTIFY isEnableDetectDoorChanged)
    Q_PROPERTY(bool isEnableDoorBell READ isEnableDoorBell WRITE setIsEnableDoorBell NOTIFY isEnableDoorBellChanged)

public:
    explicit HSSData(QObject *parent = 0);

signals:
    void usernameChanged();
    void cameraUrlChanged();
    void isEnableDetectMotionChanged();
    void isEnableDetectDoorChanged();
    void isEnableDoorBellChanged();


public slots:
    QString cameraUrl() const;
    void setCameraUrl(const QString &cameraUrl);

    QString username() const;
    void setUsername(const QString &username);

    bool isEnableDetectMotion() const;
    void setIsEnableDetectMotion(bool isEnableDetectMotion);

    bool isEnableDetectDoor() const;
    void setIsEnableDetectDoor(bool isEnableDetectDoor);

    bool isEnableDoorBell() const;
    void setIsEnableDoorBell(bool isEnableDoorBell);

private:
    QString m_username;
    QString m_cameraUrl;

    bool m_isEnableDetectMotion;
    bool m_isEnableDetectDoor;
    bool m_isEnableDoorBell;
};

#endif // HSSDATA_H
