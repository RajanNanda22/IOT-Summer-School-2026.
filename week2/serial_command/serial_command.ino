```cpp
/*
 * Serial Command Interface
 * Commands:
 * LED_ON
 * LED_OFF
 * BLINK_X (X = 1-9)
 * STATUS
 * RESET
 */

const int LED = LED_BUILTIN;
int blinkCounter = 0;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);

  Serial.begin(9600);
  Serial.println("Serial Command Interface Ready");
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();

    if (cmd == "LED_ON") {
      digitalWrite(LED, HIGH);
      Serial.println("LED ON");
    }

    else if (cmd == "LED_OFF") {
      digitalWrite(LED, LOW);
      Serial.println("LED OFF");
    }

    else if (cmd.startsWith("BLINK_")) {
      if (cmd.length() == 7 && isDigit(cmd[6])) {
        int times = cmd.substring(6).toInt();

        if (times >= 1 && times <= 9) {
          for (int i = 0; i < times; i++) {
            digitalWrite(LED, HIGH);
            delay(300);
            digitalWrite(LED, LOW);
            delay(300);
            blinkCounter++;
          }

          Serial.print("Blink Count: ");
          Serial.println(blinkCounter);
        } else {
          Serial.println("ERROR: Unknown command");
        }
      } else {
        Serial.println("ERROR: Unknown command");
      }
    }

    else if (cmd == "STATUS") {
      Serial.println("----- STATUS -----");
      Serial.print("LED State: ");
      Serial.println(digitalRead(LED) ? "ON" : "OFF");

      Serial.print("Blink Counter: ");
      Serial.println(blinkCounter);
    }

    else if (cmd == "RESET") {
      blinkCounter = 0;
      Serial.println("Blink counter reset");
    }

    else {
      Serial.println("ERROR: Unknown command");
    }
  }
}
```
