/*
  Project- DC Motor Speed Control with L298N
  Name - Rajan Nanda 
  Date - 6-7-2026

  Components:
  - Arduino Uno
  - L298N Motor Driver
  - DC Motor
  - Potentiometer
  - 2 Push Buttons

  Connections:
  ENA -> Pin 9 (PWM)
  IN1 -> Pin 7
  IN2 -> Pin 8

  Potentiometer -> A0

  Direction Button -> Pin 2
  Start/Stop Button -> Pin 3

  Buttons use INPUT_PULLUP
*/

const int ENA = 9;
const int IN1 = 7;
const int IN2 = 8;

const int potPin = A0;
const int dirButton = 2;
const int stateButton = 3;

bool direction = true;      // true = Forward
bool motorRunning = true;

int lastDirState = HIGH;
int lastMotorState = HIGH;

void setup() {

  Serial.begin(9600);

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(dirButton, INPUT_PULLUP);
  pinMode(stateButton, INPUT_PULLUP);
}

void loop() {

  int potValue = analogRead(potPin);

  int pwmValue = map(potValue, 0, 1023, 0, 255);
  int speedPercent = map(pwmValue, 0, 255, 0, 100);

  // Direction button
  int dirState = digitalRead(dirButton);

  if (dirState == LOW && lastDirState == HIGH) {
    direction = !direction;
    delay(200);
  }

  lastDirState = dirState;

  // Start/Stop button
  int motorState = digitalRead(stateButton);

  if (motorState == LOW && lastMotorState == HIGH) {
    motorRunning = !motorRunning;
    delay(200);
  }

  lastMotorState = motorState;

  // Motor control
  if (motorRunning) {

    analogWrite(ENA, pwmValue);

    if (direction) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
    }
    else {
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
    }

  } else {

    analogWrite(ENA, 0);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
  }

  // Serial Monitor Output
  Serial.print("Direction: ");
  Serial.print(direction ? "Forward" : "Reverse");

  Serial.print(" | Speed: ");
  Serial.print(speedPercent);
  Serial.print("%");

  Serial.print(" | State: ");
  Serial.println(motorRunning ? "Running" : "Stopped");

  delay(200);
}
