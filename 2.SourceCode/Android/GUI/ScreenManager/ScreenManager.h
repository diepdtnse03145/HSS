#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <QObject>
#include <QUrl>
#include <QStateMachine>

class ScreenManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QUrl currentScreenSource MEMBER m_currentScreenSource NOTIFY currentScreenChanged)
public:
    explicit ScreenManager(QObject *parent = 0);
    void run();

signals:
    void currentScreenChanged(QUrl);
    void loginToMainScr();
    void cameraToMainScr();
    void mainToCameraScr();
    void mainToSettingScr();
    void settingToMainScr();
    void doorBellToMainScr();
    void mainToDoorBellScr();
    void mainToActivityLogScr();
    void activityLogToMainScr();
    void settingToLoginScr();
    void changePassToSettingScr();
    void settingToChangePassScr();

public slots:

private:
    QStateMachine machine;
    QUrl m_currentScreenSource;
};

#endif // SCREENMANAGER_H
