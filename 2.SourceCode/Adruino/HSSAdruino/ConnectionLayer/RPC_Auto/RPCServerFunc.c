#include "../ConnectionLayer.h"
#include "../RPCServer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Arduino.h>

void _receiveMsg(char *msg)
{
    char* funcName = strtok(msg, " ");
    Serial.println(funcName);
    if (!strcmp(funcName, "ad_moeFunc"))
    {
        int ad_moeFunc_arg1 = atoi(strtok(NULL, " "));
        ad_moeFunc(ad_moeFunc_arg1);
    }

    if (!strcmp(funcName, "ad_ledOn"))
    {
        ad_ledOn();
    }



    if (!strcmp(funcName, "ad_ledOff"))
    {
        ad_ledOff();
    }

      if (!strcmp(funcName, "ad_PIRon"))
    {
        ad_PIRon();
    }

      if (!strcmp(funcName, "ad_SwitchOn"))
    {
        ad_SwitchOn();
    }

     if (!strcmp(funcName, "ad_PIRoff"))
    {
        ad_PIRoff();
    }

     if (!strcmp(funcName, "ad_SwitchOff"))
    {
        ad_SwitchOff();
    }
}
