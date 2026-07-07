/*
  Project - Servo Motor Sweep
  Name  - Rajan Nanda
  Date - 6-7-2026
  Components:
  - Arduino Uno
  - SG90 Servo Motor
  - Potentiometer
  - Push Button

  Connections:
  Servo Signal -> Pin 9
  Potentiometer Middle Pin -> A0
  Button -> Pin 2
  Button uses INPUT_PULLUP
*/

#include <Servo.h>

Servo myServo;

const int servoPin = 9;
const int potPin = A0;
const int buttonPin = 2;

int potValue;
int angle;

void setup() {

  Serial.begin(9600);

  myServo.attach(servoPin);

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {

  // Read potentiometer
  potValue = analogRead(potPin);

  // Map potentiometer to servo angle
  angle = map(potValue, 0, 1023, 0, 180);

  // Move servo
  myServo.write(angle);

  // Display angle
  Serial.print("Servo Angle: ");
  Serial.print(angle);
  Serial.println(" degrees");

  // Button pressed?
  if (digitalRead(buttonPin) == LOW) {

    // Sweep 0 to 180
    for (int pos = 0; pos <= 180; pos++) {
      myServo.write(pos);
      delay(10);
    }

    // Sweep 180 to 0
    for (int pos = 180; pos >= 0; pos--) {
      myServo.write(pos);
      delay(10);
    }
  }

  delay(100);
}
