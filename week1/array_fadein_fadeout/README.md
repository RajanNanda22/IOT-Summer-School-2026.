# Arduino PWM LED Fade Effect

## Overview

This project demonstrates how to create a smooth LED fading effect using **Pulse Width Modulation (PWM)** on an Arduino. Six LEDs connected to PWM-capable pins gradually increase in brightness (fade in) and then decrease in brightness (fade out), one LED at a time.

The program uses the `analogWrite()` function to control LED brightness by varying the PWM duty cycle.

---

## Components Required

* Arduino Uno (or compatible board)
* 6 × LEDs
* 6 × 220Ω Resistors
* Breadboard
* Jumper Wires

---

## Pin Configuration

| LED   | Arduino PWM Pin |
| ----- | --------------- |
| LED 1 | D3              |
| LED 2 | D5              |
| LED 3 | D6              |
| LED 4 | D9              |
| LED 5 | D10             |
| LED 6 | D11             |

---

## Working Principle

1. All six LED pins are configured as outputs.
2. The program selects one LED at a time.
3. The LED brightness gradually increases from **0** to **255** (Fade In).
4. The brightness then gradually decreases from **255** to **0** (Fade Out).
5. After completing one LED, the program repeats the process for the next LED.
6. Once all six LEDs have faded in and out, the sequence starts again.

---

## PWM Brightness Levels

The Arduino controls LED brightness using PWM values:

| PWM Value | Brightness         |
| --------- | ------------------ |
| 0         | OFF                |
| 64        | Low                |
| 128       | Medium             |
| 192       | High               |
| 255       | Maximum Brightness |

---

## Features

* Smooth fade-in and fade-out animation
* Sequential control of six LEDs
* Uses Arduino PWM outputs
* Simple implementation with loops
* Continuous repeating animation

---

## Program Flow

```text id="9kew3z"
Start
   │
   ▼
Initialize LED Pins
   │
   ▼
Select LED
   │
   ▼
Fade In (0 → 255)
   │
   ▼
Fade Out (255 → 0)
   │
   ▼
Next LED
   │
   ▼
Repeat Forever
```

---

## Learning Outcomes

* Understanding PWM (Pulse Width Modulation)
* Using `analogWrite()` for brightness control
* Working with arrays in Arduino
* Using nested `for` loops
* Creating smooth LED animations
* Controlling multiple output devices efficiently

---

## Folder Structure

```text id="rq9x5w"
pwm_led_fade/
├── pwm_led_fade.ino
└── README.md
```

---

## Future Improvements

* Fade all LEDs simultaneously.
* Add button-controlled speed adjustment.
* Create breathing and wave lighting effects.
* Implement non-blocking timing using `millis()`.
* Synchronize LEDs to music or sound input.

---

## Author

**Rajan Nanda**

Arduino PWM LED Fade Effect Project

