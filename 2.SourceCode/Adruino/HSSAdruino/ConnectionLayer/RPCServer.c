#include "RPCServer.h"
#include <Arduino.h>

int ledPin = 13;
int inputPin = 2;
int pirState = LOW;
int switchPin = 3;
int switchState = LOW;
int StatoSwitch = HIGH;
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
    Serial.println("1234");
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

void ad_PIRoff()
{
    Serial.println("PIR deactivated");
}
void ad_SwitchOn()
{
    Serial.println("Door active");
    StatoSwitch = digitalRead(switchPin); //Leggo il valore del Reed
    if (StatoSwitch == HIGH)
        {
            digitalWrite(ledPin, LOW);
            Serial.println("Door closed");

        }
        else
        {
            digitalWrite(ledPin, HIGH);
            Serial.println("Door opened");
        }
}

void ad_SwitchOff()
{
    Serial.println("Door deactivated");
}
