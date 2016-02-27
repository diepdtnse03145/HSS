#ifndef RPCSERVER_H
#define RPCSERVER_H

#include "ConnectionLayer.h"



extern int inputPin ;
extern int pirState ;
extern int ledPin;
extern int switchPin;
extern int switchState;
extern int StatoSwitch;
extern bool lockLow;
extern bool takeLowTime;
void ad_moeFunc(int moeVl);
void ad_ledOn();
void ad_ledOff();
void ad_PIRon();
void ad_SwitchOn();
void ad_SwitchOff();
void ad_PIRoff();
#endif //RPCSERVER_H

