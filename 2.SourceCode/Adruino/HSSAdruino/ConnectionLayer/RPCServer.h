#ifndef RPCSERVER_H
#define RPCSERVER_H

#include "ConnectionLayer.h"
#include "../HSSSensor.h"


void ad_ledOn();
void ad_ledOff();

void ad_requestPirVal();
void ad_requestBellVal();
void ad_requestSwitchVal();
void ad_init();

#endif //RPCSERVER_H

