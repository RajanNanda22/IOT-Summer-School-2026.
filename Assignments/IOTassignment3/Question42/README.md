# Automated Plant Watering System

## Problem Statement

A horticulture farmer in Jammu & Kashmir requires an automated irrigation system for a saffron farm. The system should periodically monitor soil moisture and irrigate the field only when the soil is dry. Since saffron is highly sensitive to overwatering, irrigation must be prevented if rain is detected. Rain detection is performed using both an LDR as a local overcast/rain proxy and the OpenWeatherMap API for online weather information. The system also supports manual watering with a safety lockout period to prevent repeated activation. Sensor readings and watering events are logged to Google Sheets over Wi-Fi.

---

## Solution Approach

The ESP32 continuously monitors soil moisture and ambient light levels. Soil moisture is classified into **Dry**, **Optimal**, or **Wet** zones based on configurable thresholds. An LDR is used as a local indicator of cloudy or rainy conditions, while the OpenWeatherMap API provides real-time weather information to confirm rainfall.

If the soil is dry and neither the LDR nor the weather API indicates rain, the ESP32 activates a relay (simulated using an LED in Wokwi) to operate the water pump. A manual override button allows the user to start irrigation at any time; however, a **5-minute lockout** prevents repeated manual activation.

A 16×2 I2C LCD displays the current soil moisture percentage, soil condition, and the time since the last watering event. The ESP32 also uploads sensor readings and system status to Google Sheets using a Google Apps Script web application.

---

## Features

* Soil moisture monitoring
* Dry, Optimal, and Wet moisture classification
* Automatic irrigation control
* LDR-based rain detection
* OpenWeatherMap API rain detection
* Manual watering override
* 5-minute manual override lockout
* 16×2 I2C LCD status display
* Wi-Fi connectivity
* Google Sheets cloud logging
* Serial Monitor diagnostics

---

## Hardware Components

* ESP32 DevKit V1
* Soil Moisture Sensor
* LDR (Light Dependent Resistor)
* 10 kΩ Resistor (for LDR voltage divider)
* Push Button
* LED (Relay/Pump simulation)
* 220 Ω Resistor
* 16×2 I2C LCD
* Breadboard and Jumper Wires

---

## Pin Connections

| Component                 | ESP32 Pin |
| ------------------------- | --------- |
| Soil Moisture Sensor (AO) | GPIO 34   |
| LDR Output                | GPIO 35   |
| Push Button               | GPIO 18   |
| Pump LED / Relay          | GPIO 19   |
| LCD SDA                   | GPIO 21   |
| LCD SCL                   | GPIO 22   |
| LCD VCC                   | 5V        |
| LCD GND                   | GND       |

---

## Software Requirements

* Arduino IDE
* ESP32 Board Package
* WiFi Library
* HTTPClient Library
* ArduinoJson Library
* LiquidCrystal_I2C Library
* OpenWeatherMap API Key
* Google Apps Script (Web App)
* Wokwi Simulator (optional)

---

## Working Principle

1. Connect the ESP32 to the Wi-Fi network.
2. Read soil moisture and convert it into a percentage.
3. Classify soil as **Dry**, **Optimal**, or **Wet**.
4. Detect possible rainfall using:

   * LDR sensor
   * OpenWeatherMap API
5. If the soil is dry and no rain is detected, activate the water pump.
6. Display the current system status on the LCD.
7. Upload sensor data and watering status to Google Sheets.
8. Allow manual watering through the push button with a 5-minute lockout after each manual activation.

---

## Sample Serial Output

```text
-----------------------
Moisture : 22%
State    : DRY
LDR Rain : NO
API Rain : NO
Last Watered : 120 sec
Conditions OK - Starting Pump
```

```text
-----------------------
Moisture : 75%
State    : WET
LDR Rain : YES
API Rain : YES
Last Watered : 580 sec
Watering Skipped - Rain Detected
```

---

## Future Improvements

* Replace the LED with a real relay module and water pump.
* Use a capacitive soil moisture sensor for improved accuracy.
* Integrate an RTC module for real-time timestamps.
* Add OTA firmware updates.
* Support multiple irrigation zones.
* Develop a mobile dashboard for remote monitoring and control.

---

## Author

**Rajan Nanda**
