#include "RPCClient.h"
#include "../../HSSConstant.h"
#include <stdio.h>

char _outBuf[_BUFFER_SIZE];
void pi_moeFunc(int vl)
{
    char funcName[] = "pi_moeFunc";
    sprintf(_outBuf,"%s %d",funcName, vl);
    _sendMsg(_outBuf);
}
