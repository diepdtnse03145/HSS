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
};

#endif // SCREENMANAGER_H
