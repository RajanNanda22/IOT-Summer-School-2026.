/*
  Q27 - Relay Controlled AC Device Simulation
  Name - Rajan Nanda
  Date - 6-7-2026
  Components:
  - Arduino Uno
  - DHT11 Sensor
  - Relay Module (or LED for simulation)
  - Push Button

  Connections:
  DHT11 Data -> Pin 2
  Relay/LED -> Pin 8
  Button -> Pin 7 (INPUT_PULLUP)

  Function:
  - Relay ON if temperature > 32°C
  - Relay OFF if temperature < 28°C
  - Manual override button toggles relay state
  - Logs all relay state changes with temperature
*/

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int relayPin = 8;
const int buttonPin = 7;

bool relayState = false;
bool lastRelayState = false;

int lastButtonState = HIGH;

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(relayPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  digitalWrite(relayPin, LOW);
}

void loop() {

  float temperature = dht.readTemperature();

  if (isnan(temperature)) {
    Serial.println("Failed to read DHT11!");
    delay(2000);
    return;
  }

  // Automatic Control with Hysteresis
  if (temperature > 32.0) {
    relayState = true;
  }
  else if (temperature < 28.0) {
    relayState = false;
  }

  // Manual Override
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {

    relayState = !relayState;

    Serial.print("Manual Override -> Relay ");
    Serial.print(relayState ? "ON" : "OFF");
    Serial.print(" | Temp: ");
    Serial.print(temperature);
    Serial.println(" °C");

    delay(250);
  }

  lastButtonState = buttonState;

  // Update Relay
  digitalWrite(relayPin, relayState);

  // Log only when relay changes state
  if (relayState != lastRelayState) {

    Serial.print("Relay ");
    Serial.print(relayState ? "ON" : "OFF");
    Serial.print(" | Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");

    lastRelayState = relayState;
  }

  delay(2000);
}
