#include "ConnectionLayer.h"
#include <stdlib.h>
#include <stdio.h>
#include <Arduino.h>

void _sendMsg(char *msg)
{
    Serial.println(msg);
}
