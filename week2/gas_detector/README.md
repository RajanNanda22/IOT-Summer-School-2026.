# Arduino Gas Leak Detection System

## Overview

This project implements a simple **Gas Leak Detection System** using an Arduino and an analog gas sensor (such as the MQ series). The Arduino continuously monitors the gas concentration and activates visual and audible alerts when predefined threshold values are exceeded.

The gas sensor readings are displayed on the Serial Monitor for real-time monitoring.

---

## Components Required

* Arduino Uno (or compatible board)
* MQ Gas Sensor (MQ-2/MQ-3/MQ-5 or similar)
* 1 × LED
* 1 × 220Ω Resistor
* 1 × Piezo Buzzer
* Breadboard
* Jumper Wires

---

## Pin Configuration

| Component                  | Arduino Pin |
| -------------------------- | ----------- |
| Gas Sensor (Analog Output) | A0          |
| Warning LED                | D4          |
| Piezo Buzzer               | D7          |

---

## Working Principle

1. The gas sensor continuously measures the surrounding gas concentration.
2. The analog value is read using `analogRead(A0)`.
3. The sensor value is displayed on the Serial Monitor.
4. If the sensor value reaches **200 or above**:

   * The warning LED turns ON.
5. If the sensor value reaches **355 or above**:

   * The buzzer sounds at **523 Hz (C5 note)**.
6. When the gas concentration drops below the threshold values:

   * The LED turns OFF.
   * The buzzer stops.

---

## Alert Levels

| Gas Sensor Value | Action                        |
| ---------------: | ----------------------------- |
|        Below 200 | Normal operation              |
|        200 – 354 | Warning LED ON                |
|    355 and above | Warning LED ON + Buzzer Alarm |

---

## Features

* Real-time gas concentration monitoring
* LED warning indicator
* Audible alarm using a buzzer
* Serial Monitor output for debugging
* Adjustable threshold values in the source code
* Simple and low-cost gas detection system

---

## Example Serial Output

```text id="vngpl8"
Gas Sensor Reading:
145
173
198
214
Warning LED ON
289
341
358
Buzzer Activated
376
```

---

## Program Flow

```text id="9k7n94"
Start
   │
   ▼
Initialize Pins
   │
   ▼
Read Gas Sensor
   │
   ▼
Display Value
   │
   ▼
Value ≥ 200 ?
   │
 ┌─Yes───────────────┐
 │                   │
 ▼                   │
Turn LED ON          │
 │                   │
 ▼                   │
Value ≥ 355 ?        │
 │                   │
 ├─Yes──────────────► Activate Buzzer
 │
 └─No───────────────► Continue Monitoring
```

---

## Learning Outcomes

* Reading analog sensor values using `analogRead()`
* Using threshold-based decision making
* Controlling LEDs with `digitalWrite()`
* Generating sound using the `tone()` function
* Monitoring sensor data through the Serial Monitor
* Building a basic safety monitoring system

---

## Folder Structure

```text id="l8rzja"
gas_leak_detection/
├── gas_leak_detection.ino
└── README.md
```

---

## Future Improvements

* Display gas levels on an LCD or OLED screen.
* Send SMS or email alerts using a GSM or Wi-Fi module.
* Add multiple warning levels with different LED colors.
* Log sensor readings to an SD card.
* Integrate with an IoT dashboard for remote monitoring.

---

## Author

**Rajan Nanda**

Arduino Gas Leak Detection System Project

