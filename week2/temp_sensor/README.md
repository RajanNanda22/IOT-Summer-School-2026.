# Arduino Temperature Monitoring System with 16×2 LCD

## Overview

This project demonstrates a **Temperature Monitoring System** using an Arduino, an analog temperature sensor, and a **16×2 LCD display**. The Arduino reads the analog value from the temperature sensor, converts it into a temperature value, and displays the result on both the Serial Monitor and the LCD screen.

The project uses the **Adafruit LiquidCrystal** library to interface with the LCD.

---

## Components Required

* Arduino Uno (or compatible board)
* Temperature Sensor (LM35 or compatible)
* 16×2 LCD Display (I2C or supported by Adafruit LiquidCrystal)
* Breadboard
* Jumper Wires

---

## Software Requirements

* Arduino IDE
* Adafruit LiquidCrystal Library

---

## Pin Configuration

| Component                 | Arduino Pin                                           |
| ------------------------- | ----------------------------------------------------- |
| Temperature Sensor Output | A0                                                    |
| 16×2 LCD                  | Configured through the Adafruit LiquidCrystal library |

---

## Working Principle

1. The temperature sensor continuously measures the surrounding temperature.
2. The Arduino reads the analog sensor value using `analogRead(A0)`.
3. The value is converted into a temperature reading using the `map()` function.
4. The calculated temperature is:

   * Displayed on the **16×2 LCD**
   * Printed to the **Serial Monitor**
5. The display updates continuously with the latest reading.

---

## Features

* Real-time temperature monitoring
* Displays temperature on a 16×2 LCD
* Serial Monitor output for debugging
* Uses analog sensor input
* Simple and easy-to-understand implementation
* Compatible with Arduino Uno and similar boards

---

## Example LCD Output

```text id="t5gkxt"
Temp Value=
28
```

---

## Example Serial Output

```text id="5mnxjq"
28
29
29
30
31
30
29
```

---

## Program Flow

```text id="jlwmph"
Start
   │
   ▼
Initialize LCD
   │
   ▼
Read Temperature Sensor
   │
   ▼
Convert Analog Value
   │
   ▼
Display Temperature on LCD
   │
   ▼
Print Temperature to Serial Monitor
   │
   ▼
Repeat Continuously
```

---

## Learning Outcomes

* Reading analog sensor values with `analogRead()`
* Converting sensor readings into useful values
* Displaying information on a 16×2 LCD
* Using the Adafruit LiquidCrystal library
* Serial communication for debugging
* Interfacing sensors with Arduino

---

## Folder Structure

```text id="jp2nnw"
temperature_monitor/
├── temperature_monitor.ino
└── README.md
```

---

## Future Improvements

* Display the temperature in both Celsius and Fahrenheit.
* Add maximum and minimum temperature tracking.
* Trigger a buzzer or fan when the temperature exceeds a threshold.
* Store temperature readings on an SD card.
* Send sensor data to an IoT cloud platform for remote monitoring.

---

## Author

**Rajan Nanda**

Arduino Temperature Monitoring System Project

