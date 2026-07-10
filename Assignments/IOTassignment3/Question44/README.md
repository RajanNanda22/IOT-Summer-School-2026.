# Smart Greenhouse Monitoring and Control System

## Problem Statement

Greenhouses require continuous monitoring of environmental conditions to ensure healthy plant growth. Temperature, humidity, and light intensity must remain within optimal ranges to maximize crop yield. This project implements an IoT-based greenhouse monitoring system using an ESP32 that automatically controls heating, ventilation, and lighting while publishing sensor data to an MQTT broker for remote monitoring.

---

## Solution Approach

The system uses an ESP32 to monitor temperature and humidity through a DHT22 sensor and ambient light using an LDR. A moving average filter is applied to the LDR readings to reduce noise and provide stable light measurements.

Based on predefined thresholds with hysteresis, the ESP32 automatically controls a heater, ventilation fan, and artificial lighting. The current environmental conditions and actuator states are displayed on a 16×2 I2C LCD, which cycles through multiple information screens every three seconds.

The ESP32 connects to a Wi-Fi network and publishes sensor readings and actuator statuses to the HiveMQ public MQTT broker, allowing real-time monitoring through MQTT clients such as MQTT Explorer.

---

## Features

* Temperature monitoring using DHT22
* Humidity monitoring
* Ambient light monitoring with LDR
* Running average filter for light sensor
* Automatic heater control
* Automatic ventilation fan control
* Automatic greenhouse lighting control
* Bang-bang control with hysteresis
* 16×2 I2C LCD status display
* Wi-Fi connectivity
* MQTT data publishing
* Real-time Serial Monitor diagnostics

---

## Hardware Components

* ESP32 DevKit V1
* DHT22 Temperature & Humidity Sensor
* LDR (Light Dependent Resistor)
* 10 kΩ Resistor (for LDR voltage divider)
* 16×2 I2C LCD Display
* 3 LEDs (Heater, Fan, Light simulation)
* 220 Ω Resistors
* Breadboard
* Jumper Wires

---

## Pin Connections

| Component  | ESP32 Pin |
| ---------- | --------- |
| DHT22 Data | GPIO 4    |
| LDR Output | GPIO 34   |
| Heater LED | GPIO 25   |
| Fan LED    | GPIO 26   |
| Light LED  | GPIO 27   |
| LCD SDA    | GPIO 21   |
| LCD SCL    | GPIO 22   |
| LCD VCC    | 5V        |
| LCD GND    | GND       |

---

## Software Requirements

* Arduino IDE
* ESP32 Board Package
* WiFi Library
* PubSubClient Library
* LiquidCrystal_I2C Library
* DHT Sensor Library
* Wire Library
* MQTT Explorer (or any MQTT client)

---

## MQTT Topics

| Topic                    | Description             |
| ------------------------ | ----------------------- |
| `greenhouse/temp`        | Temperature (°C)        |
| `greenhouse/humidity`    | Humidity (%)            |
| `greenhouse/light`       | Average LDR value       |
| `greenhouse/heater`      | Heater status           |
| `greenhouse/fan`         | Fan status              |
| `greenhouse/lightStatus` | Artificial light status |

---

## Working Principle

1. Connect the ESP32 to the Wi-Fi network.
2. Read temperature and humidity from the DHT22 sensor.
3. Read ambient light using the LDR and calculate its running average.
4. Apply hysteresis-based control logic:

   * Turn on the heater if the temperature is below the lower threshold.
   * Turn on the fan if the temperature or humidity exceeds the upper threshold.
   * Turn on greenhouse lighting when ambient light is low.
5. Display sensor values and actuator states on the LCD.
6. Publish all sensor readings and device states to the MQTT broker every three seconds.
7. Print diagnostic information to the Serial Monitor.

---

## Sample Serial Output

```text
------ GREENHOUSE DATA ------
Temperature: 20.5 C
Humidity   : 62.3 %
Light Avg  : 1245
Heater:0 Fan:0 Light:1
-----------------------------
```

```text
------ GREENHOUSE DATA ------
Temperature: 16.8 C
Humidity   : 58.1 %
Light Avg  : 980
Heater:1 Fan:0 Light:1
-----------------------------
```

---

## Future Improvements

* Replace LEDs with actual relays controlling greenhouse equipment.
* Add soil moisture sensing and automated irrigation.
* Store historical data in a cloud database.
* Implement MQTT subscriptions for remote control.
* Develop a web dashboard for visualization and analytics.
* Add SMS or email alerts for abnormal environmental conditions.

---

## Author

**Rajan Nanda**
