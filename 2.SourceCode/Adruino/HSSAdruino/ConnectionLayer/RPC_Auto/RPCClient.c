#include "RPCClient.h"
#include "../../HSSConstant.h"
#include <stdio.h>

char _outBuf[_BUFFER_SIZE];

void pi_returnPirValue(int vl)
{
    char funcName[] = "pi_returnPirValue";
    sprintf(_outBuf,"%s %d",funcName, vl);
    _sendMsg(_outBuf);
}

void pi_returnBellValue(int vl)
{
    char funcName[] = "pi_returnBellValue";
    sprintf(_outBuf,"%s %d",funcName, vl);
    _sendMsg(_outBuf);
}

void pi_returnSwitchValue(int vl)
{
    char funcName[] = "pi_returnSwitchValue";
    sprintf(_outBuf,"%s %d",funcName, vl);
    _sendMsg(_outBuf);
}
