# IoT Water Tank Level Monitoring System

## Problem Statement

Efficient water management requires continuous monitoring of water tank levels to prevent overflow and water shortages. This project implements an IoT-based water level monitoring system using an ESP32 and an ultrasonic sensor. The measured water level is displayed locally through LEDs and a buzzer while being uploaded to the ThingSpeak cloud platform for remote monitoring and data visualization.

---

## Solution Approach

The ESP32 measures the distance between the ultrasonic sensor and the water surface using the HC-SR04 sensor. To reduce fluctuations caused by noisy sensor readings, a rolling average filter is applied to the last five measurements.

Based on the measured distance, the system classifies the water level into **Normal**, **Warning**, or **Critical**. Three LEDs provide visual indication of the tank status, while a buzzer generates different alerts when the water level reaches warning or critical conditions.

The ESP32 connects to a Wi-Fi network and uploads the averaged distance and water level status to a ThingSpeak channel every 15 seconds, enabling cloud-based monitoring and historical data logging.

---

## Features

* Water level measurement using HC-SR04 ultrasonic sensor
* Rolling average filtering for stable measurements
* Three-level water status detection

  * Normal
  * Warning
  * Critical
* Visual indication using Green, Yellow, and Red LEDs
* Audible alerts using a buzzer
* Wi-Fi connectivity
* Cloud logging to ThingSpeak
* Real-time Serial Monitor output

---

## Hardware Components

* ESP32 DevKit V1
* HC-SR04 Ultrasonic Sensor
* Green LED
* Yellow LED
* Red LED
* Passive Buzzer
* 220 Ω Resistors
* Breadboard
* Jumper Wires

---

## Pin Connections

| Component       | ESP32 Pin |
| --------------- | --------- |
| HC-SR04 Trigger | GPIO 5    |
| HC-SR04 Echo    | GPIO 18   |
| Buzzer          | GPIO 4    |
| Green LED       | GPIO 12   |
| Yellow LED      | GPIO 13   |
| Red LED         | GPIO 14   |
| Sensor VCC      | 5V        |
| Sensor GND      | GND       |

---

## Software Requirements

* Arduino IDE
* ESP32 Board Package
* WiFi Library
* HTTPClient Library
* ThingSpeak Account
* ThingSpeak Channel with API Write Key

---

## Water Level Thresholds

| Distance from Sensor | Tank Status | LED    | Buzzer            |
| -------------------- | ----------- | ------ | ----------------- |
| > 30 cm              | Normal      | Green  | OFF               |
| 15–30 cm             | Warning     | Yellow | Intermittent Tone |
| < 15 cm              | Critical    | Red    | Continuous Tone   |

---

## ThingSpeak Fields

| Field   | Data                                                       |
| ------- | ---------------------------------------------------------- |
| Field 1 | Average Distance (cm)                                      |
| Field 2 | Water Level Status (0 = Normal, 1 = Warning, 2 = Critical) |

---

## Working Principle

1. Connect the ESP32 to the Wi-Fi network.
2. Measure the water level using the HC-SR04 ultrasonic sensor.
3. Compute the rolling average of the last five distance readings.
4. Classify the water level into Normal, Warning, or Critical.
5. Update LEDs and buzzer based on the detected water level.
6. Display live readings and status on the Serial Monitor.
7. Upload averaged sensor data to the ThingSpeak cloud every 15 seconds.

---

## Sample Serial Output

```text
Connecting WiFi...
WiFi Connected!

Raw: 42.8 cm | Avg: 41.9
Level: NORMAL

Sending to TS...
HTTP Response: 200
```

```text
Raw: 22.6 cm | Avg: 24.1
Level: WARNING

Sending to TS...
HTTP Response: 200
```

```text
Raw: 10.8 cm | Avg: 11.6
Level: CRITICAL

Sending to TS...
HTTP Response: 200
```

---

## Future Improvements

* Display water level percentage on an LCD or OLED display.
* Send SMS or email alerts when the water level becomes critical.
* Add an automatic water pump controller.
* Integrate MQTT for real-time cloud communication.
* Develop a web or mobile dashboard for remote monitoring.
* Store long-term historical data for analytics and forecasting.

---

## Author

**Rajan Nanda**
