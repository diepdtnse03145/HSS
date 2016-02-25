#ifndef RPCSERVER_H
#define RPCSERVER_H

#include "ConnectionLayer.h"



extern int inputPin ;
extern int pirState ;
extern int ledPin;
extern int switchPin;
extern int switchState;
extern int StatoSwitch;
void ad_moeFunc(int moeVl);
void ad_ledOn();
void ad_ledOff();
void ad_PIRon();
void ad_SwitchOn();
void ad_PIRoff();
void ad_SwitchOff();
#endif //RPCSERVER_H

