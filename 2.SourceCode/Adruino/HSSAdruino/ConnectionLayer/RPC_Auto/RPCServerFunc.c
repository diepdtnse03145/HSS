#include "../ConnectionLayer.h"
#include "../RPCServer.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void _receiveMsg(char *msg)
{
    char* funcName = strtok(msg, " ");
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

    if (!strcmp(funcName, "mloc"))
    {
        mloc();
    }
}
