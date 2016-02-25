#include "RPCServer.h"
#include <Arduino.h>

int ledPin = 13;
int inputPin = 2;
int pirState = LOW;
int switchPin = 3;
int switchState = LOW;
int StatoSwitch = HIGH;
bool lockLow = true;
bool takeLowTime;
void ad_moeFunc(int moeVl)
{
    //
}

void ad_ledOn()
{
    Serial.println("ad_ledOn");
    digitalWrite(ledPin, HIGH);
}

void ad_ledOff()
{
    Serial.println("ad_ledOff");
    digitalWrite(ledPin, LOW);
}

void ad_PIRon()
{
    Serial.println("PIR active");
    while (1) {
        int valPir = digitalRead(inputPin);
        if (valPir == HIGH)
        {                                               // check if the input is HIGH
            digitalWrite(ledPin, HIGH);                     // turn LED ON
            if (pirState == LOW)                            // we have just turned on
            {
                // We only want to print on the output change, not state
                pirState = HIGH;
                Serial.println("Motion detected");

            }
        } else
        {
            digitalWrite(ledPin, LOW);                  // turn LED OFF
            if (pirState == HIGH)                       // we have just turned off
            {
                Serial.println("Motion ended!");          // We only want to print on the output change, not state
                pirState = LOW;
            }
        }
    }
}

void ad_PIRoff()
{
    Serial.println("PIR deactivated");
}
void ad_SwitchOn()
{
    Serial.println("Door active");
    while (1) {
        StatoSwitch = digitalRead(switchPin);
        if (StatoSwitch == HIGH) {
            digitalWrite(ledPin, LOW);
            if(lockLow){
                lockLow = false;
                Serial.println("Door closed");
                delay(50);
            }
            takeLowTime = true;
        }
        else {
            digitalWrite(ledPin, HIGH);
            if(takeLowTime){
                takeLowTime = false;
                lockLow = true;
                Serial.println("Door opened ");      //output
                delay(50);
            }
        }
    }
}

void ad_SwitchOff()
{
    Serial.println("Door deactivated");
}
