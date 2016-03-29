#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include <QObject>
#include <QUrl>
#include <QStateMachine>

class ScreenManager : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool isLogin MEMBER m_isLogin NOTIFY isLoginChanged)
    Q_PROPERTY(QUrl currentScreenSource MEMBER m_currentScreenSource NOTIFY currentScreenChanged)
public:
    explicit ScreenManager(QObject *parent = 0);
    void run();

    bool isLogin() const;
    void setIsLogin(bool isLogin);

signals:
    void isLoginChanged(bool);
    void currentScreenChanged(QUrl);

public slots:    
    void toLoginScr();
    void toActivityLogScr();
    void toCameraScr();
    void toChangePassScr();
    void toDoorBellScr();
    void toSettingScr();
    void toMainScr();

private:
    QUrl m_currentScreenSource;
    bool m_isLogin;
};

#endif // SCREENMANAGER_H
