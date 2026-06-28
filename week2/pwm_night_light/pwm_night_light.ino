```cpp
/*
 * PWM Fading Night Light
 * PWM LED  : Pin 9
 * Mode Button : Pin 2
 *
 * Mode 1 : Slow Breathing (3 sec)
 * Mode 2 : Fast Pulse (0.5 sec)
 * Mode 3 : SOS Pattern (... --- ...)
 */

const int ledPin = 9;
const int buttonPin = 2;

int mode = 1;
bool lastButtonState = HIGH;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  Serial.begin(9600);
  Serial.println("Mode 1: Slow Breathing");
}

void checkButton() {
  bool currentState = digitalRead(buttonPin);

  if (lastButtonState == HIGH && currentState == LOW) {
    mode++;

    if (mode > 3)
      mode = 1;

    Serial.print("Current Mode: ");

    if (mode == 1)
      Serial.println("Slow Breathing");
    else if (mode == 2)
      Serial.println("Fast Pulse");
    else
      Serial.println("SOS");

    delay(250);   // debounce
  }

  lastButtonState = currentState;
}

void breathe(int delayTime) {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(delayTime);
    checkButton();
    if (mode != 1 && mode != 2) return;
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(delayTime);
    checkButton();
    if (mode != 1 && mode != 2) return;
  }
}

void dot() {
  analogWrite(ledPin,255);
  delay(250);
  analogWrite(ledPin,0);
  delay(250);
}

void dash() {
  analogWrite(ledPin,255);
  delay(750);
  analogWrite(ledPin,0);
  delay(250);
}

void sos() {

  dot();
  checkButton();
  if(mode!=3)return;

  dot();
  checkButton();
  if(mode!=3)return;

  dot();
  checkButton();
  if(mode!=3)return;

  dash();
  checkButton();
  if(mode!=3)return;

  dash();
  checkButton();
  if(mode!=3)return;

  dash();
  checkButton();
  if(mode!=3)return;

  dot();
  checkButton();
  if(mode!=3)return;

  dot();
  checkButton();
  if(mode!=3)return;

  dot();

  delay(1000);
}

void loop() {

  checkButton();

  switch(mode){

    case 1:
      // About 3 second breathing cycle
      breathe(6);
      break;

    case 2:
      // About 0.5 second breathing cycle
      breathe(1);
      break;

    case 3:
      sos();
      break;
  }
}
```
