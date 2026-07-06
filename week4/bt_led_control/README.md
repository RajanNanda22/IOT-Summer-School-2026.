# Bluetooth LED Controller (HC-05 + Arduino)

## Objective

Control three LEDs wirelessly using an HC-05 Bluetooth module and an Android Bluetooth Terminal application.

---

## Components Required

- Arduino Uno
- HC-05 Bluetooth Module
- Red LED
- Green LED
- Blue LED
- 3 × 220Ω Resistors
- Breadboard
- Jumper Wires
- Android Phone

---

## Circuit Connections

### LEDs

| LED | Arduino Pin |
|------|-------------|
| Red | D8 |
| Green | D9 |
| Blue | D10 |

Each LED should have a 220Ω resistor connected in series.

### HC-05 Module

| HC-05 | Arduino |
|--------|----------|
| VCC | 5V |
| GND | GND |
| TXD | RX (D0) |
| RXD | TX (D1)* |

*Use a voltage divider on Arduino TX to HC-05 RX if possible.

---

## Bluetooth Pairing Instructions

1. Power the Arduino.
2. HC-05 LED starts blinking rapidly.
3. Open Bluetooth settings on your Android phone.
4. Search for nearby devices.
5. Select **HC-05**.
6. Enter the default pairing PIN:
   - **1234**
   - or **0000**
7. Pair successfully.
8. Open any Bluetooth Terminal App.
9. Connect to HC-05.
10. Send commands listed below.

---

## Bluetooth Commands

| Command | Action |
|----------|--------|
| R | Turn Red LED ON |
| G | Turn Green LED ON |
| B | Turn Blue LED ON |
| X | Turn OFF all LEDs |
| F | Flash all LEDs 5 times |

---

## Example Session

```
Send: R
Output:
Red LED ON

Send: G
Output:
Green LED ON

Send: B
Output:
Blue LED ON

Send: F
Output:
Flashing LEDs...

Send: X
Output:
All LEDs OFF
```

---

## Working Principle

- Arduino continuously listens for Bluetooth data through the HC-05 module.
- Each received character corresponds to a specific LED action.
- The `switch` statement processes incoming commands.
- LEDs are controlled using `digitalWrite()`.
- The Flash command blinks all LEDs five times with a short delay.

---

## Learning Outcomes

- Serial communication
- Bluetooth communication using HC-05
- Android-to-Arduino wireless control
- Digital output control
- Using switch-case statements in Arduino
- Implementing simple command-based interfaces

---

## Author
Rajan Nanda
