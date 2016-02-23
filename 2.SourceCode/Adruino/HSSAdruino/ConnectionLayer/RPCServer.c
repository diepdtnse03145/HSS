#include "RPCServer.h"
#include <Arduino.h>

void ad_moeFunc(int moeVl)
{
    //
}

void ad_ledOn()
{
    Serial.println("ad_ledOn");
    digitalWrite(13, HIGH);
}

void ad_ledOff()
{
    Serial.println("ad_ledOff");
    digitalWrite(13, LOW);
}

void mloc()
{
        digitalWrite(13, HIGH);


}
