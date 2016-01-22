
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int switchPin = 3;              // choose the pin for magnetic switch
int switchState = LOW;          // we start, assuming door is closed
int buttonPin = 4;
int buttonState = LOW;          // we start, assuming button is not pressed

void setup() {
  pinMode(switchPin, INPUT);                        // declare switch as input
  pinMode(ledPin, OUTPUT);                          // declare LED as output
  pinMode(inputPin, INPUT);                         // declare sensor as input
  pinMode(buttonPin, INPUT);
  digitalWrite(switchPin, HIGH);
  Serial.begin(9600);

}

void loop() {
  int valPir = digitalRead(inputPin);                      // read input value
  int valButton = digitalRead(buttonPin);
  int valSwitch = digitalRead(switchPin);

  // ======================= BUTTON 
  if(valButton == HIGH) {
    digitalWrite(ledPin, HIGH);
    if(buttonState == LOW) 
    {
    Serial.println("Someone pressed the doorbell!");           // We only want to print on the output change, not state
    buttonState = HIGH;
    } 
  } else {
      digitalWrite(ledPin, LOW);                  // turn LED OFF
      if (buttonState == HIGH)                       // we have just turned off
          {
          buttonState = LOW;
          }
        }
   
  // ======================= BUTTON 

  if (valSwitch == HIGH) {                                               // check if the input is HIGH
    digitalWrite(ledPin, HIGH);                     // turn LED ON
    if (switchState == LOW)                           // we have just turned on
      {
      Serial.println("The door is opened!");           // We only want to print on the output change, not state
      switchState = HIGH;
      }
    } else 
        {
        digitalWrite(ledPin, LOW);                  // turn LED OFF
        if (switchState == HIGH)                       // we have just turned off
          {
          Serial.println("The door is closed!");          // We only want to print on the output change, not state
          switchState = LOW;
          }
        }


  // =================== Start PIR
  if (valPir == HIGH)
    {                                               // check if the input is HIGH
    digitalWrite(ledPin, HIGH);                     // turn LED ON
    if (pirState == LOW)                            // we have just turned on
      {
      Serial.println("Motion detected!");           // We only want to print on the output change, not state
      pirState = HIGH;
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
  // =================== End PIR
}

