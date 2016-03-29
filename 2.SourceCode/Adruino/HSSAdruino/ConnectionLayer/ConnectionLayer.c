#include "ConnectionLayer.h"
#include <stdlib.h>
#include <stdio.h>
#include <Arduino.h>

bool m_isInited = false;

void _sendMsg(char *msg)
{
    if (m_isInited) {
        Serial.println(msg);
    }
}
