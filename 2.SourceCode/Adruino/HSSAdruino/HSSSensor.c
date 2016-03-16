#include "HSSSensor.h"
#include "ConnectionLayer/RPC_Auto/RPCClient.h"
#include <Arduino.h>

int pirValue;
int switchValue;
int bellValue;
int tmp;

void readPirValue()
{
    tmp = digitalRead(_PIR_PIN);                    //read sensor value
    if (pirValue != tmp) {                          //if sensor value changed
        pirValue = tmp;
        pi_returnPirValue(pirValue);                //call Pi server
    }
}

void readDoorBellValue()
{
    tmp = digitalRead(_BELL_PIN);                      //read sensor value
    if (bellValue != tmp) {                                //if sensor value changed
        bellValue = tmp;
        pi_returnBellValue(bellValue);                      //call Pi server
    }
}

void readSwitchValue()
{
    tmp = digitalRead(_SWITCH_PIN);                      //read sensor value
    if (switchValue != tmp) {                                //if sensor value changed
        switchValue = tmp;
        pi_returnSwitchValue(switchValue);                      //call Pi server
    }
}

void updateSensorValue()
{
    readPirValue();
    readDoorBellValue();
    readSwitchValue();
}
