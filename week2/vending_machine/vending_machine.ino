```cpp
/*
 * Vending Machine State Machine
 *
 * State Transition Diagram:
 *
 *           Insert Coin
 * IDLE -----------------> COIN_INSERTED
 *  ^                          |
 *  | Cancel                   | Select Item
 *  |                          v
 *  +------------------- ITEM_SELECTED
 *                           |
 *                           | Dispense Item
 *                           v
 *                      DISPENSING
 *                           |
 *                           | Complete
 *                           v
 *                          IDLE
 *
 * Buttons:
 * D2 - Insert Coin
 * D3 - Select Item
 * D4 - Cancel
 *
 * LEDs:
 * D8  - IDLE
 * D9  - COIN_INSERTED
 * D10 - ITEM_SELECTED / DISPENSING
 */

const int coinBtn = 2;
const int selectBtn = 3;
const int cancelBtn = 4;

const int ledIdle = 8;
const int ledCoin = 9;
const int ledAction = 10;

enum State {
  IDLE,
  COIN_INSERTED,
  ITEM_SELECTED,
  DISPENSING
};

State currentState = IDLE;

void updateLEDs() {
  digitalWrite(ledIdle, LOW);
  digitalWrite(ledCoin, LOW);
  digitalWrite(ledAction, LOW);

  switch (currentState) {
    case IDLE:
      digitalWrite(ledIdle, HIGH);
      break;

    case COIN_INSERTED:
      digitalWrite(ledCoin, HIGH);
      break;

    case ITEM_SELECTED:
    case DISPENSING:
      digitalWrite(ledAction, HIGH);
      break;
  }
}

void changeState(State newState, String name) {
  currentState = newState;
  updateLEDs();
  Serial.print("State -> ");
  Serial.println(name);
}

void setup() {

  pinMode(coinBtn, INPUT_PULLUP);
  pinMode(selectBtn, INPUT_PULLUP);
  pinMode(cancelBtn, INPUT_PULLUP);

  pinMode(ledIdle, OUTPUT);
  pinMode(ledCoin, OUTPUT);
  pinMode(ledAction, OUTPUT);

  Serial.begin(9600);

  updateLEDs();

  Serial.println("State -> IDLE");
}

void loop() {

  if (digitalRead(cancelBtn) == LOW) {
    changeState(IDLE, "IDLE");
    delay(300);
    return;
  }

  switch (currentState) {

    case IDLE:

      if (digitalRead(coinBtn) == LOW) {
        changeState(COIN_INSERTED, "COIN_INSERTED");
        delay(300);
      }

      break;

    case COIN_INSERTED:

      if (digitalRead(selectBtn) == LOW) {
        changeState(ITEM_SELECTED, "ITEM_SELECTED");
        delay(500);

        changeState(DISPENSING, "DISPENSING");
        delay(2000);

        changeState(IDLE, "IDLE");
      }

      break;

    case ITEM_SELECTED:
      break;

    case DISPENSING:
      break;
  }
}
```
