#ifndef PIENGINE_H
#define PIENGINE_H

#include "../Connection/connectionbase.h"

class PiEngine : public ConnectionBase
{
public:
    PiEngine(QObject* parent = 0);

public slots:
    void pi_changePassword(const QString& oldpwd, const QString& newpwd);
    void pi_enableDetectMotion(const bool& enable);
    void pi_enableSystemStatus(const bool& enable);
    void pi_enableDetectDoor(const bool& enable);
    void pi_enableDoorBell(const bool& enable);

private:
    void _hss_recvMsg(const QString &msg) override;

    void and_changePwResult(bool result);
};

#endif // PIENGINE_H
