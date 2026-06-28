```cpp
/*
  Digital Piano using Buzzer
  Buttons:
  D2 - Do
  D3 - Re
  D4 - Mi
  D5 - Fa
  D6 - Mode Toggle
  Buzzer - D8
*/

const int buzzer = 8;

const int btnDo = 2;
const int btnRe = 3;
const int btnMi = 4;
const int btnFa = 5;
const int modeBtn = 6;

bool majorMode = true;
bool lastModeState = HIGH;

// Major Scale
int majorNotes[4] = {262, 294, 330, 349};

// Minor Scale
int minorNotes[4] = {262, 294, 311, 349};

void setup() {
  pinMode(btnDo, INPUT_PULLUP);
  pinMode(btnRe, INPUT_PULLUP);
  pinMode(btnMi, INPUT_PULLUP);
  pinMode(btnFa, INPUT_PULLUP);
  pinMode(modeBtn, INPUT_PULLUP);

  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  // Toggle between Major and Minor
  bool currentMode = digitalRead(modeBtn);

  if (lastModeState == HIGH && currentMode == LOW) {
    majorMode = !majorMode;

    if (majorMode)
      Serial.println("Major Mode");
    else
      Serial.println("Minor Mode");

    delay(200);
  }

  lastModeState = currentMode;

  bool d = digitalRead(btnDo) == LOW;
  bool r = digitalRead(btnRe) == LOW;
  bool m = digitalRead(btnMi) == LOW;
  bool f = digitalRead(btnFa) == LOW;

  int pressed = d + r + m + f;

  // Two or more buttons -> Sol
  if (pressed >= 2) {
    tone(buzzer, 392);
    return;
  }

  int *notes = majorMode ? majorNotes : minorNotes;

  if (d)
    tone(buzzer, notes[0]);
  else if (r)
    tone(buzzer, notes[1]);
  else if (m)
    tone(buzzer, notes[2]);
  else if (f)
    tone(buzzer, notes[3]);
  else
    noTone(buzzer);
}
```
