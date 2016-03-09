#include "HSSSensor.h"
#include "ConnectionLayer/RPC_Auto/RPCClient.h"
#include <Arduino.h>

int pirValue;
int switchValue;
int bellValue;

void readPirValue()
{
    int tmp = digitalRead(_PIR_PIN);                      //read sensor value
    if (pirValue != tmp) {                                //if sensor value changed
        pirValue = tmp;
        pi_returnPirValue(pirValue);                      //call Pi server
    }
}

void readDoorBellValue()
{
    int tmp = digitalRead(_BELL_PIN);                      //read sensor value
    if (bellValue != tmp) {                                //if sensor value changed
        bellValue = tmp;
        pi_returnPirValue(bellValue);                      //call Pi server
    }
}

void readSwitchValue()
{
    int tmp = digitalRead(_SWITCH_PIN);                      //read sensor value
    if (switchValue != tmp) {                                //if sensor value changed
        switchValue = tmp;
        pi_returnPirValue(switchValue);                      //call Pi server
    }
}

void updateSensorValue()
{
    readPirValue();
    readDoorBellValue();
    readSwitchValue();
}
