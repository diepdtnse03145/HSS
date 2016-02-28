#include "RPCServer.h"
#include <Arduino.h>

int ledPin = 13;
int inputPin = 2;
int pirState = LOW;
int switchPin = 3;
int switchState = LOW;
int StatoSwitch = HIGH;
int buttonPin = 4;
int buttonState = LOW;
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

void ad_Bell()
{
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.write("1");
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }

}
void ad_PIRon()
{
    Serial.println("PIR active");
        int valPir = digitalRead(inputPin);
        if (valPir == HIGH)
        {                                               // check if the input is HIGH
            digitalWrite(ledPin, HIGH);                     // turn LED ON
            if (pirState == LOW)                            // we have just turned on
            {
                // We only want to print on the output change, not state
                pirState = HIGH;
                Serial.println("Motion detected");
                Serial.write("2");
            }
        } else
        {
            digitalWrite(ledPin, LOW);                  // turn LED OFF
            if (pirState == HIGH)                       // we have just turned off
            {
                pirState = LOW;
                Serial.println("Motion ended!");          // We only want to print on the output change, not state
                Serial.write("3");
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
        StatoSwitch = digitalRead(switchPin);
        if (StatoSwitch == HIGH) {
            digitalWrite(ledPin, LOW);
            if(lockLow){
                lockLow = false;
                Serial.write("5");
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
                Serial.write("4");
                Serial.println("Door opened ");      //output
                delay(50);
            }
        }

}

void ad_SwitchOff()
{
    Serial.println("Door deactivated");
}
