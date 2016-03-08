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

    /*
    viewerState->addTransition(this,SIGNAL(viewerToManager()),managerState);
    managerState->addTransition(this,SIGNAL(managerToViewer()),viewerState);
    */
    loginScreenState->assignProperty(this,"currentScreenSource",QUrl(LoginScreen));
    activitylogScreenState->assignProperty(this,"currentScreenSource",QUrl(ActivitylogScreen));
    cameraScreenState->assignProperty(this,"currentScreenSource",QUrl(CameraScreen));
    changePassScreenState->assignProperty(this,"currentScreenSource",QUrl(ChangePassScreen));
    doorBellScreenState->assignProperty(this,"currentScreenSource",QUrl(DoorBellScreen));
    settingScreenState->assignProperty(this,"currentScreenSource",QUrl(SettingScreen));

    machine.addState(loginScreenState);
    machine.addState(activitylogScreenState);
    machine.addState(cameraScreenState);
    machine.addState(changePassScreenState);
    machine.addState(doorBellScreenState);
    machine.addState(settingScreenState);

    machine.setInitialState(loginScreenState);
}

void ScreenManager::run()
{
    machine.start();
}


