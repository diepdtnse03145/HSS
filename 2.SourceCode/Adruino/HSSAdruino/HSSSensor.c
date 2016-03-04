#include "HSSSensor.h"
#include "ConnectionLayer/RPC_Auto/RPCClient.h"
#include <Arduino.h>

int pirValue;
int switchValue;
int bellValue;

void readPirValue()
{
    pirValue = digitalRead(_PIR_PIN);
    if (pirValue == HIGH) {                                     //Have motion
            pi_returnPirValue(pirValue);                        //call Pi server
     }
}

void readDoorBellValue()
{
    bellValue = digitalRead(_PIR_PIN);
    if (bellValue == HIGH) {                                     //Bell ring
            pi_returnBellValue(bellValue);                        //call Pi server
     }
}

void readSwitchValue()
{
    switchValue = digitalRead(_SWITCH_PIN);
    if (switchValue == HIGH) {                                     //Door openned
            pi_returnSwitchValue(switchValue);                        //call Pi server
     }
}

void updateSensorValue()
{
    readPirValue();
    readDoorBellValue();
    readSwitchValue();
}
