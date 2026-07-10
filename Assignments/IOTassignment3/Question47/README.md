# IoT Patient Health Monitoring System

## Problem Statement

Continuous monitoring of a patient's vital signs is essential for the early detection of potential health issues. This project simulates a basic IoT health monitoring system using an ESP32. An LDR sensor is used as a simulated physiological input to generate heart rate and blood oxygen (SpO₂) values. The system analyzes these values and activates an alert indicator when abnormal conditions are detected.

---

## Solution Approach

The ESP32 reads analog values from an LDR sensor and applies a moving average filter to smooth out fluctuations. The filtered value is then mapped to simulated heart rate and SpO₂ readings.

The system continuously checks whether the generated vital signs fall outside predefined safe ranges. If an abnormal condition is detected, an LED is turned on as a visual alert. All readings and alert status are printed to the Serial Monitor every two seconds.

---

## Features

* Simulated heart rate monitoring
* Simulated SpO₂ monitoring
* Moving average filtering for stable readings
* Automatic abnormal condition detection
* LED-based health alert indicator
* Real-time Serial Monitor logging
* Simple and lightweight ESP32 implementation

---

## Hardware Components

* ESP32 DevKit V1
* LDR (Light Dependent Resistor)
* 10 kΩ Resistor (voltage divider)
* LED
* 220 Ω Resistor
* Breadboard
* Jumper Wires

---

## Pin Connections

| Component  | ESP32 Pin |
| ---------- | --------- |
| LDR Output | GPIO 34   |
| Alert LED  | GPIO 14   |
| LDR VCC    | 3.3V      |
| LDR GND    | GND       |

---

## Software Requirements

* Arduino IDE
* ESP32 Board Package
* Arduino Core Library

---

## Monitoring Thresholds

| Parameter  | Normal Range | Alert Condition           |
| ---------- | ------------ | ------------------------- |
| Heart Rate | 50–120 bpm   | Below 50 or above 120 bpm |
| SpO₂       | ≥ 94%        | Below 94%                 |

---

## Working Principle

1. Read the analog value from the LDR sensor.
2. Apply a moving average filter using the last five samples.
3. Map the filtered value to simulated heart rate and SpO₂ readings.
4. Compare the readings against predefined safety thresholds.
5. Turn the alert LED ON if any parameter is outside the safe range.
6. Print the current heart rate, SpO₂, and alert status to the Serial Monitor every two seconds.

---

## Sample Serial Output

```text
--------------------------
Heart Rate : 76 bpm
SpO2 : 98 %
Alert : NO
--------------------------
```

```text
--------------------------
Heart Rate : 128 bpm
SpO2 : 92 %
Alert : YES
--------------------------
```

---

## Future Improvements

* Replace the LDR with a real pulse oximeter sensor (MAX30102).
* Add body temperature monitoring.
* Upload patient data to a cloud platform using MQTT or HTTP.
* Develop a mobile or web dashboard for remote monitoring.
* Send SMS or email notifications during emergency conditions.
* Store historical patient data for trend analysis.

---

## Author

**Rajan Nanda**
