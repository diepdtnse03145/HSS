#include "hssdata.h"

HSSData::HSSData(QObject *parent) : QObject(parent)
{

}

QString HSSData::cameraUrl() const
{
    return m_cameraUrl;
}

void HSSData::setCameraUrl(const QString &cameraUrl)
{
    if (m_cameraUrl != cameraUrl) {
        m_cameraUrl = cameraUrl;
        emit cameraUrlChanged();
    }
}

QString HSSData::username() const
{
    return m_username;
}

void HSSData::setUsername(const QString &username)
{
    if (m_username != username) {
        m_username = username;
        emit usernameChanged();
    }
}

bool HSSData::isEnableDoorBell() const
{
    return m_isEnableDoorBell;
}

void HSSData::setIsEnableDoorBell(bool isEnableDoorBell)
{
    if (m_isEnableDoorBell != isEnableDoorBell) {
        m_isEnableDoorBell = isEnableDoorBell;
        emit isEnableDoorBellChanged();
    }
}

QUrl HSSData::doorBellPic() const
{
    return m_doorBellPic;
}

void HSSData::setDoorBellPic(const QUrl &pic)
{
    if (m_doorBellPic != pic) {
        m_doorBellPic = pic;
        emit doorBellPicChanged();
    }
}

bool HSSData::isEnableDetectDoor() const
{
    return m_isEnableDetectDoor;
}

void HSSData::setIsEnableDetectDoor(bool isEnableDetectDoor)
{
    if (m_isEnableDetectDoor != isEnableDetectDoor) {
        m_isEnableDetectDoor = isEnableDetectDoor;
        emit isEnableDetectDoorChanged();
    }
}

bool HSSData::isEnableDetectMotion() const
{
    return m_isEnableDetectMotion;
}

void HSSData::setIsEnableDetectMotion(bool isEnableDetectMotion)
{
    if (m_isEnableDetectMotion != isEnableDetectMotion) {
        m_isEnableDetectMotion = isEnableDetectMotion;
        emit isEnableDetectMotionChanged();
    }
}
