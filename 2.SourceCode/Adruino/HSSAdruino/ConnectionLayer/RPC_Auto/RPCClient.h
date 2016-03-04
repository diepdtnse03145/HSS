#ifndef RPCCLIENT_H
#define RPCCLIENT_H
#include "../ConnectionLayer.h"
#include "../../HSSConstant.h"

extern char _outBuf[_BUFFER_SIZE];

extern void pi_returnPirValue(int vl);
extern void pi_returnBellValue(int vl);
extern void pi_returnSwitchValue(int vl);

#endif //RPCCLIENT_H
