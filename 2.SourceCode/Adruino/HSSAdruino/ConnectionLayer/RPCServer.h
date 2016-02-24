#ifndef RPCSERVER_H
#define RPCSERVER_H

#include "ConnectionLayer.h"



extern int inputPin ;               // choose the input pin (for PIR sensor)
extern int pirState ;
extern int ledPin;
extern int switchPin;
extern int switchState;
void ad_moeFunc(int moeVl);
void ad_ledOn();
void ad_ledOff();
void ad_PIRon();
void ad_SwitchOn();
#endif //RPCSERVER_H

