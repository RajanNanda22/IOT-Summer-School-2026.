# Arduino Reaction Time Game

## Overview

This project is a simple **Reaction Time Game** built using an Arduino, an RGB LED, and a push button. The game measures how quickly a player reacts when the **Green LED** turns ON.

Before the game starts, the RGB LED flashes random colors with random delays to prevent the player from predicting when the signal will appear. Once the Green LED lights up, the player must press the button as quickly as possible. The reaction time is calculated using the `millis()` function and displayed on the Serial Monitor.

---

## Components Required

* Arduino Uno (or compatible board)
* 1 × RGB LED (Common Cathode/Common Anode as wired)
* 3 × 220Ω Resistors
* 1 × Push Button
* 1 × 10kΩ Resistor (or use `INPUT_PULLUP`)
* Breadboard
* Jumper Wires

---

## Pin Configuration

| Component   | Arduino Pin |
| ----------- | ----------- |
| Red LED     | D3          |
| Green LED   | D5          |
| Blue LED    | D6          |
| Push Button | D2          |

---

## Game Rules

1. Upload the sketch to the Arduino.
2. Open the Serial Monitor at **9600 baud**.
3. The RGB LED flashes random colors with random timing.
4. Wait until the **Green LED** turns ON and the Serial Monitor displays **"GO!"**.
5. Press the push button as quickly as possible.
6. Your reaction time is calculated and displayed in milliseconds.
7. A new round starts automatically after a short delay.

---

## Features

* Random LED flashing before each round
* Random waiting time before the "GO!" signal
* Reaction time measurement using `millis()`
* Reaction time displayed on the Serial Monitor
* Automatic game restart after each round
* Simple and interactive gameplay

---

## Example Serial Output

```text
Reaction Time Game
Wait for the GREEN LED and press the button!

New Round Starting...

GO!
Reaction Time: 284 ms

New Round Starting...

GO!
Reaction Time: 198 ms
```

---

## Working Principle

* The Arduino generates random LED colors and random delays using the `random()` function.
* After a random waiting period, the Green LED turns ON.
* The program records the current time with `millis()`.
* When the button is pressed, the elapsed time is calculated.
* The reaction time is printed to the Serial Monitor.

---

## Learning Outcomes

* Using RGB LEDs with Arduino
* Reading push button input
* Generating random numbers with `random()`
* Measuring elapsed time using `millis()`
* Using the Serial Monitor for user interaction
* Creating an interactive embedded system game

---

## Folder Structure

```text
reaction_time_game/
├── reaction_time_game.ino
└── README.md
```

---

## Future Improvements

* Add a high-score system.
* Display reaction time on an LCD or OLED display.
* Include multiple difficulty levels.
* Detect and penalize false starts.
* Add sound effects using a buzzer.

---

## Author

**Rj Rajan**

Arduino Reaction Time Game Project

