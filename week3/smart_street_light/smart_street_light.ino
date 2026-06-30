/*
  Q23 - Smart Street Light
  LDR + PIR Sensor

  Features:
  - Daylight -> LED OFF
  - Night -> Motion Detection Enabled
  - Motion Detected -> LED Full Brightness (100%) for 30 seconds
  - No Motion for 30 seconds -> LED Dim (20%)
  - Logs every event with timestamp
*/

const int ldrPin = A0;
const int pirPin = 2;
const int ledPin = 9;

const int ldrThreshold = 500;

unsigned long motionTimer = 0;
bool motionActive = false;

unsigned long previousSecond = 0;
unsigned long elapsedSeconds = 0;

void setup() {

  Serial.begin(9600);

  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);

  analogWrite(ledPin, 0);
}

void printTimestamp() {

  unsigned long hrs = elapsedSeconds / 3600;
  unsigned long mins = (elapsedSeconds % 3600) / 60;
  unsigned long secs = elapsedSeconds % 60;

  if (hrs < 10) Serial.print("0");
  Serial.print(hrs);
  Serial.print(":");

  if (mins < 10) Serial.print("0");
  Serial.print(mins);
  Serial.print(":");

  if (secs < 10) Serial.print("0");
  Serial.print(secs);
}

void logEvent(String event) {

  Serial.print("[");
  printTimestamp();
  Serial.print("] EVENT: ");
  Serial.println(event);
}

void loop() {

  // Simple software clock
  if (millis() - previousSecond >= 1000) {
    previousSecond = millis();
    elapsedSeconds++;
  }

  int ldrValue = analogRead(ldrPin);

  if (ldrValue > ldrThreshold) {

    analogWrite(ledPin, 0);

    if (motionActive) {
      motionActive = false;
    }

    static bool dayLogged = false;

    if (!dayLogged) {
      logEvent("Daylight detected - Street Light OFF");
      dayLogged = true;
    }

  } else {

    static bool nightLogged = false;

    if (!nightLogged) {
      logEvent("Night detected - Motion Detection Enabled");
      nightLogged = true;
    }

    int motion = digitalRead(pirPin);

    if (motion == HIGH) {

      analogWrite(ledPin, 255);

      motionTimer = millis();

      if (!motionActive) {
        logEvent("Motion detected - LED ON (100%)");
      }

      motionActive = true;

    } else {

      if (motionActive && millis() - motionTimer >= 30000) {

        analogWrite(ledPin, 51);   // 20% brightness

        logEvent("No motion for 30 seconds - LED Dimmed (20%)");

        motionActive = false;
      }
    }
  }

  delay(100);
}
