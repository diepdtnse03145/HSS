#include "ScreenManager.h"
#include "ScreenDefine.h"

#include <QtCore>

ScreenManager::ScreenManager(QObject *parent) : QObject(parent)
{

}

void ScreenManager::run()
{
    toLoginScr();
}

void ScreenManager::toLoginScr()
{
    if (m_currentScreenSource != LoginScreen) {
        m_currentScreenSource = LoginScreen;
        emit currentScreenChanged(m_currentScreenSource);
    }
}

void ScreenManager::toActivityLogScr()
{
    if (m_currentScreenSource != ActivitylogScreen) {
        m_currentScreenSource = ActivitylogScreen;
        emit currentScreenChanged(m_currentScreenSource);
    }
}

void ScreenManager::toCameraScr()
{
    if (m_currentScreenSource != CameraScreen) {
        m_currentScreenSource = CameraScreen;
        emit currentScreenChanged(m_currentScreenSource);
    }
}

void ScreenManager::toChangePassScr()
{
    if (m_currentScreenSource != ChangePassScreen) {
        m_currentScreenSource = ChangePassScreen;
        emit currentScreenChanged(m_currentScreenSource);
    }
}

void ScreenManager::toDoorBellScr()
{
    if (m_currentScreenSource != DoorBellScreen) {
        m_currentScreenSource = DoorBellScreen;
        emit currentScreenChanged(m_currentScreenSource);
    }
}

void ScreenManager::toSettingScr()
{
    if (m_currentScreenSource != SettingScreen) {
        m_currentScreenSource = SettingScreen;
        emit currentScreenChanged(m_currentScreenSource);
    }
}

void ScreenManager::toMainScr()
{
    if (m_currentScreenSource != MainScreen) {
        m_currentScreenSource = MainScreen;
        emit currentScreenChanged(m_currentScreenSource);
    }
}


