# Arduino Push Button LED Blinker

## Overview

This project demonstrates how to control an LED using a push button with an Arduino. When the push button is pressed and held, the LED connected to pin **3** blinks continuously. The button state is also printed to the Serial Monitor for monitoring and debugging.

The program continuously checks the button input. As long as the button remains pressed, the LED blinks with a fixed delay. Once the button is released, the LED stops blinking.

---

## Components Required

* Arduino Uno (or compatible board)
* 1 × LED
* 1 × 220Ω Resistor
* 1 × Push Button
* 1 × 10kΩ Resistor (or use `INPUT_PULLUP`)
* Breadboard
* Jumper Wires

---

## Pin Configuration

| Component   | Arduino Pin |
| ----------- | ----------- |
| Push Button | D2          |
| LED         | D3          |

---

## Working Principle

1. The push button is connected to **digital pin 2**.
2. The LED is connected to **digital pin 3**.
3. The Arduino continuously reads the button state using `digitalRead()`.
4. While the button is pressed (`HIGH`):

   * The LED turns ON.
   * Waits for **200 ms**.
   * The LED turns OFF.
   * Waits for **100 ms**.
   * The button state is printed to the Serial Monitor.
5. When the button is released, the LED stops blinking.

---

## Features

* LED controlled by a push button
* Continuous blinking while the button is held
* Serial Monitor displays the current button state
* Simple demonstration of digital input and output
* Easy to modify for different blink speeds

---

## Example Serial Output

```text id="5z9r8g"
9600 baud

Button State:
1
1
1
1
1
```

The value **1** indicates that the push button is currently pressed.

---

## Program Flow

```text id="p9ms0x"
Start
   │
   ▼
Initialize Pins
   │
   ▼
Read Button State
   │
   ▼
Button Pressed?
   │
 ┌─Yes──────────────┐
 │                  │
 ▼                  │
Blink LED           │
Print Button State  │
 │                  │
 └────Repeat────────┘
        │
       No
        ▼
Read Button Again
```

---

## Learning Outcomes

* Using `pinMode()` for input and output pins
* Reading push button input with `digitalRead()`
* Controlling an LED using `digitalWrite()`
* Displaying data on the Serial Monitor
* Implementing loops based on button input
* Understanding basic Arduino digital I/O

---

## Folder Structure

```text id="4eyjpi"
button_led_blink/
├── button_led_blink.ino
└── README.md
```

---

## Future Improvements

* Add software debouncing for the push button.
* Use `INPUT_PULLUP` to simplify wiring.
* Replace `delay()` with `millis()` for non-blocking operation.
* Add multiple blinking patterns.
* Control the blink speed using a potentiometer.

---

## Author

**Rajan Nanda**

Arduino Push Button LED Blinker Project

  
