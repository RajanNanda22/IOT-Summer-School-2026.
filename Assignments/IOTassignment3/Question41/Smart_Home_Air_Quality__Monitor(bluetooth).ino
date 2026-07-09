/*
-------------------------------------------------------
Project : Smart Home Air Quality Monitor
Author  : Rajan Nanda 
Date    : 07-07-2026

Description:
- Reads air quality using MQ-2 gas sensor.
- Reads temperature and humidity using DHT22.
- Displays air quality using RGB LED.
- Activates buzzer based on severity level.
- Logs data in CSV format to Serial Monitor.
- Sends alerts to an Android phone via Bluetooth.
-------------------------------------------------------
*/

#include <DHT.h>
#include "BluetoothSerial.h"

// Create Bluetooth Serial object
BluetoothSerial SerialBT;

// -------------------- DHT Sensor --------------------
#define DHTPIN 4
#define DHTTYPE DHT22          
DHT dht(DHTPIN, DHTTYPE);

// -------------------- Pin Definitions --------------------
#define MQ2_PIN    34

#define RED_PIN    25
#define GREEN_PIN  26
#define BLUE_PIN   27

#define BUZZER     14

// Stores the clean-air baseline value of MQ-2
int baseline = 0;

// -------------------------------------------------------
// Function to control RGB LED
// -------------------------------------------------------
void setColor(bool r, bool g, bool b) {
  digitalWrite(RED_PIN, r);
  digitalWrite(GREEN_PIN, g);
  digitalWrite(BLUE_PIN, b);
}

void setup() {

  Serial.begin(115200);

  // Start Bluetooth
  SerialBT.begin("ESP32_AirMonitor");

  // Initialize DHT sensor
  dht.begin();

  // Configure output pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // ---------------- MQ-2 Calibration ----------------
  // Wait for sensor to stabilize
  Serial.println("Stabilizing MQ-2 Sensor...");
  delay(5000);

  // Take 30 readings in clean air
  long sum = 0;

  for (int i = 0; i < 30; i++) {
    sum += analogRead(MQ2_PIN);
    delay(200);
  }

  baseline = sum / 30;

  Serial.print("Baseline Value: ");
  Serial.println(baseline);

  // CSV Header
  Serial.println("Timestamp, MQ-2 Value, DHT Temp, DHT Humidity, Severity");
}

void loop() {

  // Read MQ-2 sensor
  int gasRaw = analogRead(MQ2_PIN);

  // Difference from baseline
  int diff = gasRaw - baseline;

  // Read DHT sensor
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Check if DHT sensor failed
  if (isnan(temp) || isnan(hum)) {
    Serial.println("DHT Sensor Error!");
    delay(2000);
    return;
  }

  String status;

  // Turn buzzer OFF before checking conditions
  noTone(BUZZER);

  // ---------------- SAFE ----------------
  if (diff < 80) {

    status = "SAFE";

    setColor(LOW, HIGH, LOW);

    // Bluetooth Alert
    SerialBT.println("SAFE");
    SerialBT.printf("Gas:%d\n", gasRaw);
    SerialBT.printf("Temp:%.1f C\n", temp);
    SerialBT.printf("Humidity:%.1f%%\n\n", hum);

  }

  // ---------------- MODERATE ----------------
  else if (diff < 250) {

    status = "MODERATE";

    // Yellow = Red + Green
    setColor(HIGH, HIGH, LOW);

    // Medium tone
    tone(BUZZER, 1000, 200);

    // Bluetooth Alert
    SerialBT.println("WARNING");
    SerialBT.println("Moderate Smoke Detected");
    SerialBT.printf("Gas=%d\n", gasRaw);
    SerialBT.println("Check Fireplace\n");

  }

  // ---------------- DANGER ----------------
  else {

    status = "DANGER";

    setColor(HIGH, LOW, LOW);

    // Continuous high-pitched alarm
    tone(BUZZER, 2000);

    // Bluetooth Alert
    SerialBT.println("DANGER!!");
    SerialBT.println("Smoke Level Critical");
    SerialBT.printf("Gas=%d\n", gasRaw);
    SerialBT.println("Open Windows");
    SerialBT.println("Leave Room if Necessary\n");

  }

  // Create timestamp in MM:SS format
  int sec = millis() / 1000;

  char timestamp[6];

  sprintf(timestamp, "%02d:%02d", sec / 60, sec % 60);

  // ---------------- CSV Output ----------------
  Serial.print(timestamp);
  Serial.print(", ");

  Serial.print(gasRaw);
  Serial.print(", ");

  Serial.print(temp);
  Serial.print(", ");

  Serial.print(hum);
  Serial.print(", ");

  Serial.println(status);

  // Update every 2 seconds
  delay(2000);
}
