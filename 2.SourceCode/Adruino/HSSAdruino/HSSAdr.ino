#include <Arduino.h>
#include "HSSConstant.h"
#include "ConnectionLayer/ConnectionLayer.h"

char _inBuf[_BUFFER_SIZE];
int _inRes;

void setup()
{
	Serial.begin(9600);
    Serial.setTimeout(10000);
    pinMode(13, OUTPUT);
}

void loop()
{
  _inRes = Serial.readBytesUntil('\n',_inBuf,_BUFFER_SIZE - 1);
    _receiveMsg(_inBuf);
  if(_inRes) {

    memset( _inBuf, '\0', sizeof(char) * _BUFFER_SIZE);
    _inRes = 0;
  }
  }
