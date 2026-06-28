int ledPins[] = {3, 5, 6, 9, 10, 11};                        

void setup() {
  for (int i = 0; i<6; i++) {
    pinMode(ledPins[i], OUTPUT);         
  }
}

void loop() {
  for (int i = 0; i < 6; i++) { 

    // FADE IN
    for (int bright = 0; bright <= 255; bright++) {
      analogWrite(ledPins[i], bright);
      delay(3);
    }

    // FADE OUT
    for (int bright = 255; bright >= 0; bright--) {
      analogWrite(ledPins[i], bright);
      delay(3);
    }

  }
}
