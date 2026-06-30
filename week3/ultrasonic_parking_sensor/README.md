# Ultrasonic Parking Sensor

## Objective

Build a parking distance alert system using the HC-SR04 ultrasonic sensor.

---

## Components Required

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- Green LED
- Yellow LED
- Red LED
- Buzzer
- 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Trig | D9 |
| Echo | D10 |
| Green LED | D2 |
| Yellow LED | D3 |
| Red LED | D4 |
| Buzzer | D5 |

---

## Distance Formula

```cpp
distance = (duration * 0.034) / 2;
```

---

## Alert Conditions

| Distance | Status | LED | Buzzer |
|----------|--------|-----|---------|
| > 50 cm | SAFE | Green ON | OFF |
| 20–50 cm | CAUTION | Yellow ON | Beep every 500 ms |
| 10–20 cm | WARNING | Red ON | Beep every 200 ms |
| < 10 cm | STOP | All LEDs flash | Continuous ON |

---

## Features

- Measures distance using HC-SR04
- Displays distance in centimeters on the Serial Monitor
- Prints parking status (SAFE, CAUTION, WARNING, STOP!)
- Uses the required distance calculation formula
- Uses `millis()` for non-blocking timing (bonus requirement)
- Controls LEDs and buzzer based on measured distance

---

## Author

Rj Rajan
