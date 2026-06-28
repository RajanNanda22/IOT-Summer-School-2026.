```cpp
/*
 * Traffic Light Controller
 * Red  : Pin 8
 * Yellow: Pin 9
 * Green : Pin 10
 * Pedestrian Button: Pin 7
 */

const int RED = 8;
const int YELLOW = 9;
const int GREEN = 10;
const int BUTTON = 7;

void printState(String state) {
  Serial.print("[");
  Serial.print(millis());
  Serial.print(" ms] ");
  Serial.println(state);
}

void redLight(unsigned long duration) {
  digitalWrite(RED, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  printState("RED");
  delay(duration);
}

void yellowLight(unsigned long duration) {
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(GREEN, LOW);
  printState("YELLOW");
  delay(duration);
}

void greenLight(unsigned long duration) {
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, HIGH);
  printState("GREEN");
  delay(duration);
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {

  // Pedestrian request
  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);

    printState("PEDESTRIAN REQUEST - RED");
    delay(8000);
    return;
  }

  redLight(5000);

  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);

    printState("PEDESTRIAN REQUEST - RED");
    delay(8000);
    return;
  }

  yellowLight(2000);

  if (digitalRead(BUTTON) == LOW) {
    digitalWrite(RED, HIGH);
    digitalWrite(YELLOW, LOW);
    digitalWrite(GREEN, LOW);

    printState("PEDESTRIAN REQUEST - RED");
    delay(8000);
    return;
  }

  greenLight(4000);
}
```
