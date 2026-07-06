/*
  Bluetooth LED Controller (HC-05 + Arduino)
  Author - Rajan Nanda 
  Date - 7-7-2026 

  Commands:
  R - Red LED ON
  G - Green LED ON
  B - Blue LED ON
  X - All LEDs OFF
  F - Flash all LEDs 5 times
*/

const int RED_LED = 8;
const int GREEN_LED = 9;
const int BLUE_LED = 10;

char command;

void setup() {

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);

  Serial.begin(9600);

  Serial.println("=== Bluetooth LED Controller ===");
  Serial.println("Commands:");
  Serial.println("R -> Red LED");
  Serial.println("G -> Green LED");
  Serial.println("B -> Blue LED");
  Serial.println("X -> All OFF");
  Serial.println("F -> Flash LEDs");
}

void loop() {

  if (Serial.available()) {

    command = Serial.read();

    switch (command) {

      case 'R':
        digitalWrite(RED_LED, HIGH);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BLUE_LED, LOW);
        Serial.println("Red LED ON");
        break;

      case 'G':
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
        digitalWrite(BLUE_LED, LOW);
        Serial.println("Green LED ON");
        break;

      case 'B':
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, LOW);
        digitalWrite(BLUE_LED, HIGH);
        Serial.println("Blue LED ON");
        break;

      case 'X':
        allOff();
        Serial.println("All LEDs OFF");
        break;

      case 'F':
        Serial.println("Flashing LEDs...");
        flashLEDs();
        break;

      default:
        Serial.println("Unknown Command");
        break;
    }
  }
}

void allOff() {
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
}

void allOn() {
  digitalWrite(RED_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(BLUE_LED, HIGH);
}

void flashLEDs() {

  for (int i = 0; i < 5; i++) {

    allOn();
    delay(300);

    allOff();
    delay(300);
  }
}
