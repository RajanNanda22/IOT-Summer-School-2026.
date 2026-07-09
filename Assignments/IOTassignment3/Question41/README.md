# Smart Home Air Quality Monitor

## Problem Statement

A family in Milan, Europe, is concerned about indoor air quality during winter when wood is burned for heating. Poor ventilation can increase carbon monoxide (CO) and smoke levels, creating health risks. The objective is to design an IoT-based air quality monitoring system that continuously measures gas concentration, temperature, and humidity, provides visual and audible alerts based on air quality, and logs data locally so that the system continues to operate even when the internet is unavailable.

---

## Solution Approach

This project uses an **ESP32** as the main controller to monitor indoor environmental conditions. An **MQ-2 gas sensor** continuously measures smoke/CO concentration, while a **DHT22 (or DHT11)** measures temperature and humidity.

At startup, the MQ-2 sensor is calibrated by recording a baseline reading in clean air. During operation, the ESP32 compares the current gas sensor reading with the baseline to determine the air quality level.

The system classifies air quality into three levels:

* **SAFE** – Green RGB LED, buzzer OFF
* **MODERATE** – Yellow RGB LED with intermittent warning beep
* **DANGER** – Red RGB LED with continuous alarm

Every two seconds, the ESP32 records the timestamp, gas sensor value, temperature, humidity, and severity level in **CSV format** on the Serial Monitor for local data logging. Since all processing is performed on the ESP32, the system remains fully functional even without an internet connection.

---

## Hardware Required

* ESP32 Development Board
* MQ-2 Gas Sensor
* DHT22 (or DHT11) Temperature & Humidity Sensor
* RGB LED (Common Cathode)
* Piezo Buzzer
* Breadboard
* Jumper Wires
* USB Cable for ESP32 Programming

---

## Pin Connections

| Component          | ESP32 Pin |
| ------------------ | --------- |
| MQ-2 Analog Output | GPIO 34   |
| DHT22 Data         | GPIO 15   |
| RGB LED (Red)      | GPIO 25   |
| RGB LED (Green)    | GPIO 26   |
| RGB LED (Blue)     | GPIO 27   |
| Buzzer             | GPIO 14   |

---

## Air Quality Thresholds

| Severity | Condition                        | RGB LED | Buzzer                   |
| -------- | -------------------------------- | ------- | ------------------------ |
| SAFE     | Gas level close to baseline      | Green   | OFF                      |
| MODERATE | Moderate increase above baseline | Yellow  | 1000 Hz warning beep     |
| DANGER   | High increase above baseline     | Red     | Continuous 2000 Hz alarm |

---

## Sample Serial Monitor Output

```text
Timestamp, MQ-2 Value, DHT11 Temp, DHT11 Humidity, Severity Level

00:01, 220 ppm, 23.4°C, 49%, SAFE
00:02, 280 ppm, 23.5°C, 50%, SAFE
00:03, 420 ppm, 23.6°C, 49%, MODERATE
00:04, 710 ppm, 23.8°C, 48%, DANGER
```

---

## Features

* MQ-2 gas sensor monitoring with baseline calibration
* Temperature and humidity monitoring using DHT22/DHT11
* Three-level air quality classification
* RGB LED status indication
* Multi-level buzzer alarm
* CSV data logging to the Serial Monitor
* Operates without an internet connection

---

## Author

**Rajan Nanda**
