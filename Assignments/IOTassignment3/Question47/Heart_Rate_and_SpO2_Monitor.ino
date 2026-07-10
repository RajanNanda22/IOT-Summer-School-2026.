/*
-------------------------------------------------------
Project : IoT Patient Health Monitoring System
Author  : Rajan Nanda
Date    : 09-07-2026

Description:
- Simulates patient health monitoring using an ESP32.
- Uses an LDR as a simulated sensor input.
- Applies a moving average filter to reduce noise.
- Generates simulated Heart Rate and SpO2 values.
- Detects abnormal conditions based on thresholds.
- Turns ON an alert LED when an abnormal condition
  is detected.
- Logs all readings to the Serial Monitor.
-------------------------------------------------------
*/

#include <Arduino.h>

// -------- Pin Definitions --------
#define LDR_PIN 34      // Analog input from LDR
#define LED_PIN 14      // Alert LED

// Number of samples used for moving average
#define N 5

// Buffer for moving average filter
int buf[N] = {0};
int idx = 0;
int sum = 0;

//-------------------------------------------------------
// Moving Average Filter
// Removes noise by averaging the last N readings
//-------------------------------------------------------
int smooth(int val) {

  // Remove oldest reading
  sum -= buf[idx];

  // Store new reading
  buf[idx] = val;

  // Add new reading to total
  sum += val;

  // Move to next buffer position
  idx = (idx + 1) % N;

  // Return average
  return sum / N;
}

//-------------------------------------------------------
// Print simulated patient vitals
//-------------------------------------------------------
void logVitals(int hr, int spo2, bool alert) {

  Serial.println("--------------------------");

  Serial.print("Heart Rate : ");
  Serial.print(hr);
  Serial.println(" bpm");

  Serial.print("SpO2       : ");
  Serial.print(spo2);
  Serial.println(" %");

  Serial.print("Alert      : ");
  Serial.println(alert ? "YES" : "NO");

  Serial.println("--------------------------");
}

//-------------------------------------------------------
void setup() {

  // Initialize Serial Monitor
  Serial.begin(115200);

  // Configure alert LED
  pinMode(LED_PIN, OUTPUT);

  Serial.println("Patient Health Monitoring Started");
}

//-------------------------------------------------------
void loop() {

  // Read raw analog value from LDR
  int rawValue = analogRead(LDR_PIN);

  // Smooth the sensor reading
  int avg = smooth(rawValue);

  // Simulate Heart Rate (40–140 bpm)
  int hr = map(avg, 0, 4095, 40, 140);

  // Simulate Blood Oxygen Level (88–100%)
  int spo2 = map(avg, 0, 4095, 88, 100);

  // Check if values are outside safe limits
  bool alert = (hr < 50 || hr > 120 || spo2 < 94);

  // Turn alert LED ON or OFF
  digitalWrite(LED_PIN, alert ? HIGH : LOW);

  // Print values to Serial Monitor
  logVitals(hr, spo2, alert);

  // Update every 2 seconds
  delay(2000);
}
