/*
-------------------------------------------------------
Project : Smart Home Air Quality Monitor
Author  : Rajan Nanda
Date    : 07-07-2026

Description:
- ESP32 + MQ-2 Gas Sensor + DHT11/DHT22
- Monitors air quality, temperature, and humidity.
- RGB LED indicates SAFE, MODERATE, or DANGER levels.
- Buzzer alarm changes tone based on severity.
- Logs sensor readings in CSV format to Serial Monitor.
-------------------------------------------------------
*/

#include <DHT.h>

// -------------------- DHT Sensor Configuration --------------------
#define DHTPIN 15
#define DHTTYPE DHT22          
DHT dht(DHTPIN, DHTTYPE);

// -------------------- MQ-2 Gas Sensor --------------------
#define MQ2_PIN 34

// -------------------- Output Devices --------------------
#define RED_PIN 25
#define GREEN_PIN 26
#define BLUE_PIN 27
#define BUZZER 14

// Stores the clean-air baseline value of the MQ-2 sensor
int baseline = 0;

// -------------------------------------------------------
// Function to control the RGB LED
// r = Red LED state
// g = Green LED state
// b = Blue LED state
// -------------------------------------------------------
void setColor(bool r, bool g, bool b) {

  digitalWrite(RED_PIN, r);
  digitalWrite(GREEN_PIN, g);
  digitalWrite(BLUE_PIN, b);
}

void setup() {

  // Start Serial Monitor
  Serial.begin(115200);

  // Initialize DHT sensor
  dht.begin();

  // Configure output pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  // ---------- MQ-2 Calibration ----------
  // Allow sensor to stabilize before taking readings
  Serial.println("Stabilizing MQ-2...");
  delay(5000);

  // Take 30 readings in clean air and calculate baseline
  int sum = 0;
  for (int i = 0; i < 30; i++) {
    sum += analogRead(MQ2_PIN);
    delay(200);
  }

  baseline = sum / 30;

  // Display baseline value
  Serial.print("Baseline: ");
  Serial.println(baseline);

  // Print CSV header
  Serial.println("Timestamp, MQ-2 Value, DHT11 Temp, DHT11 Humidity, Severity Level");
}

void loop() {

  // Read MQ-2 analog value
  int gasRaw = analogRead(MQ2_PIN);

  // Calculate increase above clean-air baseline
  int diff = gasRaw - baseline;

  // Read temperature and humidity from DHT sensor
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Check whether sensor reading is valid
  if (isnan(temp) || isnan(hum)) {
    Serial.println("DHT ERROR");
    delay(2000);
    return;
  }

  String status;

  // -------------------------------------------------------
  // Air Quality Classification
  //
  // SAFE      : Difference < 80
  // MODERATE  : Difference 80 - 249
  // DANGER    : Difference >= 250
  // -------------------------------------------------------

  // SAFE
  if (diff < 80) {

    status = "SAFE";

    // Green LED ON
    setColor(LOW, HIGH, LOW);

    // Turn buzzer OFF
    noTone(BUZZER);
  }

  // MODERATE
  else if (diff < 250) {

    status = "MODERATE";

    // Yellow = Red + Green
    setColor(HIGH, HIGH, LOW);

    // Medium warning beep
    tone(BUZZER, 1000);
    delay(200);
    noTone(BUZZER);
  }

  // DANGER
  else {

    status = "DANGER";

    // Red LED ON
    setColor(HIGH, LOW, LOW);

    // Continuous high-frequency alarm
    tone(BUZZER, 2000);
  }

  // ---------- Generate Timestamp (MM:SS) ----------
  int seconds = millis() / 1000;
  int mins = seconds / 60;
  int secs = seconds % 60;

  char timeStr[6];
  sprintf(timeStr, "%02d:%02d", mins, secs);

  // ---------- Print CSV Data ----------
  Serial.print(timeStr);
  Serial.print(", ");

  Serial.print(gasRaw);
  Serial.print(" ppm, ");

  Serial.print(temp);
  Serial.print("°C, ");

  Serial.print(hum);
  Serial.print("%, ");

  Serial.println(status);

  // Wait before taking the next reading
  delay(2000);
}
