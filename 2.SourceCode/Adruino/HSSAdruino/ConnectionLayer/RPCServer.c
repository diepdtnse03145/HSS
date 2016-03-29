#include "RPCServer.h"
#include "RPC_Auto/RPCClient.h"
#include <Arduino.h>

void ad_ledOn()
{
    digitalWrite(_LED_PIN, HIGH);
}

void ad_ledOff()
{
    digitalWrite(_LED_PIN, LOW);
}

void ad_requestPirVal()
{
    pi_returnPirValue(pirValue);
}

void ad_requestBellVal()
{
    pi_returnBellValue(bellValue);
}

void ad_requestSwitchVal()
{
    pi_returnSwitchValue(switchValue);
}

void ad_init()
{
    m_isInited = true;
}

