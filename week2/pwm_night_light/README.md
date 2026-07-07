# PWM Fading Night Light

## Overview

The **PWM Fading Night Light** is an Arduino project that demonstrates LED brightness control using **Pulse Width Modulation (PWM)**. The LED continuously performs a breathing (fade in/fade out) effect, and a push button allows switching between three different lighting modes.

The current operating mode is displayed on the Serial Monitor for easy monitoring and debugging.

---

## Features

- PWM-based LED brightness control
- Three lighting modes selectable using a push button
- Continuous breathing animation
- SOS emergency flashing pattern
- Serial Monitor displays the active mode
- Simple and beginner-friendly implementation

---

## Components Required

- Arduino Uno (or compatible board)
- 1 × LED
- 1 × 220Ω Resistor
- 1 × Push Button
- Breadboard
- Jumper Wires
- USB Cable

---

## Circuit Connections

### LED

| Component | Arduino Pin |
|----------|-------------|
| LED Anode (+) | PWM Pin 9 |
| LED Cathode (-) | GND (through 220Ω resistor) |

### Push Button

| Button Pin | Arduino Pin |
|------------|-------------|
| One Side | Digital Pin 2 |
| Other Side | GND |

> Configure the button using `INPUT_PULLUP` in the Arduino code.

---

## Working Principle

The Arduino continuously monitors the push button. Each button press cycles through one of three lighting modes:

### Mode 1 – Slow Breathing

- LED gradually fades from OFF to full brightness and back to OFF.
- One complete breathing cycle takes approximately **3 seconds**.

### Mode 2 – Fast Pulse

- LED fades much faster.
- One complete cycle takes approximately **0.5 seconds**.

### Mode 3 – SOS Pattern

The LED flashes the international Morse code distress signal:

```
... --- ...
```

Where:

- `.` = Short flash
- `-` = Long flash

The pattern repeats continuously until another mode is selected.

---

## Serial Monitor Output

Example:

```
PWM Fading Night Light

Current Mode: Slow Breathing

Current Mode: Fast Pulse

Current Mode: SOS Pattern
```

---

## PWM Explanation

PWM (Pulse Width Modulation) allows the Arduino to simulate analog output by rapidly switching a digital pin between HIGH and LOW.

The LED brightness is controlled using:

```cpp
analogWrite(ledPin, brightness);
```

Brightness values range from:

| Value | Brightness |
|-------|------------|
| 0 | OFF |
| 128 | 50% Brightness |
| 255 | Fully ON |

---

## Project Structure

```
week3/
└── pwm_fading_night_light/
    ├── pwm_fading_night_light.ino
    └── README.md
```

---

## How to Run

1. Connect the circuit according to the wiring diagram.
2. Open the Arduino sketch.
3. Select the correct board and COM port.
4. Upload the program.
5. Open the Serial Monitor (9600 baud).
6. Observe the LED breathing effect.
7. Press the push button to switch between the three modes.

---

## Expected Behavior

| Mode | Description |
|------|-------------|
| Mode 1 | Slow breathing effect (3-second cycle) |
| Mode 2 | Fast pulse effect (0.5-second cycle) |
| Mode 3 | SOS Morse code flashing pattern |

---

## Applications

- Automatic night lights
- Decorative LED lighting
- Emergency signaling systems
- PWM learning projects
- Arduino beginner projects
- Smart home lighting demonstrations

---

## Learning Outcomes

After completing this project, you will understand:

- Pulse Width Modulation (PWM)
- LED brightness control using `analogWrite()`
- Push button input handling
- Mode switching using a state variable
- Serial Monitor debugging
- Timing and LED animation techniques
- Morse code implementation for LED signaling

---

## Author

**Rajan Nanda**

