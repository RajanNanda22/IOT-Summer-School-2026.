# Traffic Light Controller using Arduino

## Overview

This project simulates a basic traffic light system using an Arduino and three LEDs. The traffic lights operate in a fixed sequence:

* 🔴 Red LED ON for **5 seconds**
* 🟡 Yellow LED ON for **2 seconds**
* 🟢 Green LED ON for **4 seconds**

A pedestrian push button is connected to **digital pin 7**. Whenever the button is pressed, the normal traffic sequence is interrupted immediately. The Red LED turns ON and remains active for **8 seconds** to allow pedestrians to cross safely. After the delay, the traffic light resumes its normal operation.

The current traffic light state along with the system uptime (`millis()`) is displayed in the Serial Monitor.

---

## Components Required

* Arduino Uno (or compatible board)
* 1 × Red LED
* 1 × Yellow LED
* 1 × Green LED
* 3 × 220Ω Resistors
* 1 × Push Button
* Breadboard
* Jumper Wires

---

## Pin Configuration

| Component   | Arduino Pin |
| ----------- | ----------- |
| Red LED     | D2          |
| Yellow LED  | D3          |
| Green LED   | D4          |
| Push Button | D7          |

---

## Working

1. The Red LED turns ON for 5 seconds.
2. The Yellow LED turns ON for 2 seconds.
3. The Green LED turns ON for 4 seconds.
4. The cycle repeats continuously.
5. If the pedestrian button is pressed:

   * The normal sequence stops immediately.
   * The Red LED turns ON.
   * Red remains ON for 8 seconds.
   * The normal traffic sequence resumes afterward.
6. Every light change is printed to the Serial Monitor with the current timestamp using `millis()`.

---

## Sample Serial Output

```text
[0 ms] RED
[5000 ms] YELLOW
[7000 ms] GREEN
[11000 ms] RED
[12500 ms] Pedestrian Button Pressed
[12501 ms] RED (Pedestrian Crossing)
```

---

## Learning Outcomes

* Digital output control using LEDs
* Reading push button input
* Using `digitalRead()` and `digitalWrite()`
* Implementing traffic light logic
* Handling external events with conditional statements
* Displaying system status using the Serial Monitor
* Using `millis()` for timestamps

---

## Folder Structure

```text
week2/
└── traffic_light/
    ├── traffic_light.ino
    └── README.md
```

---

## Author

**Rajan Nanda**

Arduino Programming – Week 2 Assignment

