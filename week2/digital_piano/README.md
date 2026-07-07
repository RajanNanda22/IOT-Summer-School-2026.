# Digital Piano using Arduino and Passive Buzzer

## Overview

This project creates a simple digital piano using an Arduino, a passive buzzer, and five push buttons. Four buttons are assigned to musical notes, while the fifth button toggles between Major and Minor scales.

Features include:

* Four musical notes (Do, Re, Mi, Fa)
* Sound plays only while a button is pressed
* Buzzer is silent when no buttons are pressed
* If two note buttons are pressed simultaneously, the buzzer plays **Sol (392 Hz)** as a chord substitute
* Scale mode can be switched between **Major** and **Minor** using a dedicated mode button

Each feature is committed separately using Git.

---

## Components Required

* Arduino Uno (or compatible board)
* 1 × Passive Buzzer
* 5 × Push Buttons
* 5 × 10kΩ Resistors (or use `INPUT_PULLUP`)
* Breadboard
* Jumper Wires

---

## Pin Configuration

| Component          | Arduino Pin |
| ------------------ | ----------- |
| Do Button          | D2          |
| Re Button          | D3          |
| Mi Button          | D4          |
| Fa Button          | D5          |
| Mode Toggle Button | D6          |
| Passive Buzzer     | D9          |

---

## Musical Notes

### Major Scale

| Note              | Frequency |
| ----------------- | --------- |
| Do                | 262 Hz    |
| Re                | 294 Hz    |
| Mi                | 330 Hz    |
| Fa                | 349 Hz    |
| Sol (Two Buttons) | 392 Hz    |

### Minor Scale

The mode button switches the piano to the Minor scale by changing the note frequencies while maintaining the same button layout.

---

## Working

1. Press one of the four note buttons to play its assigned note.
2. Release the button to stop the sound.
3. If two note buttons are pressed together, the buzzer plays **Sol (392 Hz)** instead of individual notes.
4. Press the mode toggle button to switch between Major and Minor scales.
5. The selected mode remains active until it is changed again.

---

## Git Commit History

Example commits for this assignment:

```text
Initial project setup
Add four note buttons and buzzer
Implement note playback on button press
Add two-button chord substitute (Sol)
Implement Major/Minor mode toggle
Update README documentation
```

---

## Learning Outcomes

* Reading multiple push button inputs
* Generating musical notes using `tone()`
* Stopping sound with `noTone()`
* Handling simultaneous button presses
* Implementing mode switching with a toggle button
* Organizing development using Git commits

---

## Folder Structure

```text
week2/
└── digital_piano/
    ├── digital_piano.ino
    └── README.md
```

---

## Author

**Rajan Nanda**



