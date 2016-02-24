#include "RPCServer.h"
#include <Arduino.h>



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

void ad_SwitchOn()
{
    int  StatoSwitch = digitalRead(switchPin); //Leggo il valore del Reed
    if (StatoSwitch == HIGH)
        {
            digitalWrite(ledPin, LOW);

        }
        else
        {
            digitalWrite(ledPin, HIGH);

        }
}
