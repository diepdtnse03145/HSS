
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int switchPin = 3;              // choose the pin for magnetic switch
int switchState = LOW;          // we start, assuming door is closed
int buttonPin = 4;
int buttonState = LOW;          // we start, assuming button is not pressed
int previous = LOW;
long time = 0;
int stateLED = LOW; 

boolean lockLow = true;
boolean takeLowTime;  

void setup() {
  pinMode(switchPin, INPUT);                        // declare switch as input
  pinMode(ledPin, OUTPUT);                          // declare LED as output
  pinMode(inputPin, INPUT);                         // declare sensor as input
  pinMode(buttonPin, INPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);

}

void startLED()
{
   buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}

void startPIR()
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
     Serial.write("b");
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

/*void startSwitch()
{
   int valSwitch = digitalRead(switchPin);
   if (valSwitch == HIGH) {
                            digitalWrite(ledPin, LOW);
                            if(lockLow){  
                                          lockLow = false;            
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
                    Serial.write("c");
                    delay(50);
                }
      } 
}*/

void startSwitch()
{
 int  StatoSwitch = digitalRead(switchPin); //Leggo il valore del Reed
 if (StatoSwitch == HIGH)
  {
    digitalWrite(ledPin, LOW);
  }
 else
  {
    digitalWrite(ledPin, HIGH);
   Serial.write("c");
  }
}
void loop() {                 
 startLED();  
 startSwitch();
 startPIR();
}

