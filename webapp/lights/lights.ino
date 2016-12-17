/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.



  modified 8 May 2014
  by Scott Fitzgerald
  
***********************
***********************
***********************
Updated by : OSC

Red, Yellow, Green lights
Flask Server

***********************
***********************
***********************
  
 */
  int pin_red = 10;
  int pin_yellow = 11;
  int pin_green = 12;
  int state = 0;
  int wait = 3000;
  String incomingBytes = "";   // for incoming serial data
// the setup function runs once when you press reset or power the board

void setup() {
  Serial.begin(9600);
  // initialize digital pin 13 as an output.
  pinMode(pin_red, OUTPUT);
  pinMode(pin_yellow, OUTPUT);
  pinMode(pin_green, OUTPUT);
}

void LightToggle(int pin) {
  if (digitalRead(pin) == 0) {
    state = 1;
  }
  else{
    state = 0;
  }
  digitalWrite(pin, state);    // turn the LED off by making the voltage LOW
  Serial.write(pin);
  Serial.println(state);
  //delay(wait);              // wait for a second
}

// the loop function runs over and over again forever
void loop() {
  
          // send data only when you receive data:
        if (Serial.available() > 0) {
                // read the incoming byte:
                incomingBytes = Serial.readString();
                Serial.print("I received: ");
                Serial.println(incomingBytes);
                if (incomingBytes == "red") {
                  // say what you got:
                  Serial.print("I validated: ");
                  Serial.println(incomingBytes);
                  LightToggle(pin_red);
                }
                else if (incomingBytes == "yellow") {
                  // say what you got:
                  Serial.print("I validated: ");
                  Serial.println(incomingBytes);
                  LightToggle(pin_yellow);
                }
                else if (incomingBytes == "green") {
                  // say what you got:
                  Serial.print("I validated: ");
                  Serial.println(incomingBytes);
                  LightToggle(pin_green);
                }
        }
}
