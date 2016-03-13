#include <Arduino.h>
#include "HSSConstant.h"
#include "ConnectionLayer/ConnectionLayer.h"
#include "ConnectionLayer/RPCServer.h"
#include "HSSSensor.h"

char _inBuf[_BUFFER_SIZE];
bool _inCPL = false;


void setup()
{
    Serial.begin(9600);
    Serial.setTimeout(10000);
    pinMode(_LED_PIN, OUTPUT);
    pinMode(_PIR_PIN, INPUT);
    pinMode(_SWITCH_PIN, INPUT);
    pinMode(_BELL_PIN, INPUT);
}

void loop()
{
    if(_inCPL) {
        _receiveMsg(_inBuf);
        memset( _inBuf, '\0', sizeof(char) * _BUFFER_SIZE);
        _inCPL = false;
    }
    updateSensorValue();
}

void serialEvent()
{
    while (Serial.available()) {
        char _charBuf[2];
        memset( _charBuf, '\0', sizeof(char) * 2);
        _charBuf[0] = (char)Serial.read();
        strcat(_inBuf, _charBuf);

        if (_charBuf[0] == '\n') {
            _inCPL = true;
        }
    }
}
