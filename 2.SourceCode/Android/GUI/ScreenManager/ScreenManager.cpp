#include "ScreenManager.h"
#include "ScreenDefine.h"

#include <QtCore>

ScreenManager::ScreenManager(QObject *parent) : QObject(parent)
{
    auto loginScreenState = new QState{};
    auto activitylogScreenState = new QState{};
    auto cameraScreenState = new QState{};
    auto changePassScreenState = new QState{};
    auto doorBellScreenState = new QState{};
    auto settingScreenState = new QState{};
    auto mainScreenState = new QState{};

    loginScreenState->addTransition(this,SIGNAL(loginToMainScr()),mainScreenState);
    mainScreenState->addTransition(this,SIGNAL(mainToCameraScr()),cameraScreenState);
    cameraScreenState->addTransition(this,SIGNAL(cameraToMainScr()),mainScreenState);
    mainScreenState->addTransition(this,SIGNAL(mainToSettingScr()),settingScreenState);
    settingScreenState->addTransition(this,SIGNAL(settingToMainScr()),mainScreenState);
    doorBellScreenState->addTransition(this,SIGNAL(doorBellToMainScr()),mainScreenState);
    mainScreenState->addTransition(this,SIGNAL(mainToDoorBellScr()),doorBellScreenState);
    mainScreenState->addTransition(this,SIGNAL(mainToActivityLogScr()),activitylogScreenState);
    activitylogScreenState->addTransition(this,SIGNAL(activityLogToMainScr()),mainScreenState);
    settingScreenState->addTransition(this,SIGNAL(settingToLoginScr()),loginScreenState);
    changePassScreenState->addTransition(this,SIGNAL(changePassToSettingScr()),settingScreenState);
    settingScreenState->addTransition(this,SIGNAL(settingToChangePassScr()),changePassScreenState);


    loginScreenState->assignProperty(this,"currentScreenSource",QUrl(LoginScreen));
    activitylogScreenState->assignProperty(this,"currentScreenSource",QUrl(ActivitylogScreen));
    cameraScreenState->assignProperty(this,"currentScreenSource",QUrl(CameraScreen));
    changePassScreenState->assignProperty(this,"currentScreenSource",QUrl(ChangePassScreen));
    doorBellScreenState->assignProperty(this,"currentScreenSource",QUrl(DoorBellScreen));
    settingScreenState->assignProperty(this,"currentScreenSource",QUrl(SettingScreen));
    mainScreenState->assignProperty(this,"currentScreenSource",QUrl(MainScreen));

    machine.addState(loginScreenState);
    machine.addState(activitylogScreenState);
    machine.addState(cameraScreenState);
    machine.addState(changePassScreenState);
    machine.addState(doorBellScreenState);
    machine.addState(settingScreenState);
    machine.addState(mainScreenState);

    machine.setInitialState(loginScreenState);
}

void ScreenManager::run()
{
    machine.start();
}


