# Arduino 4×4 LED Matrix Control

## Overview

This project demonstrates how to control a **4×4 LED Matrix** using an Arduino Uno. The LEDs are controlled by selecting the appropriate row and column pins. The program shows how individual LEDs and different LED patterns can be displayed by driving rows and columns with `digitalWrite()`.

The sketch includes:

* Individual LED control
* LED pattern generation
* Row and column addressing
* Matrix scanning using Arduino digital output pins

---

## Components Required

* Arduino Uno (or compatible board)
* 4×4 LED Matrix
* Breadboard
* Jumper Wires
* Current-limiting resistors (if required by the matrix)

---

## Pin Configuration

### Column Pins

| Matrix Column | Arduino Pin |
| ------------- | ----------- |
| C1            | D5          |
| C2            | D4          |
| C3            | D3          |
| C4            | D2          |

### Row Pins

| Matrix Row | Arduino Pin |
| ---------- | ----------- |
| R1         | D6          |
| R2         | D7          |
| R3         | D8          |
| R4         | D9          |

---

## Working Principle

A single LED in the matrix is turned ON by:

* Setting the required **column pin HIGH**
* Setting the corresponding **row pin LOW**
* Keeping all other columns LOW and rows HIGH

This combination completes the electrical path for only one LED.

For example:

| LED | Column | Row |
| --- | ------ | --- |
| L1  | C1     | R1  |
| L2  | C2     | R1  |
| L3  | C3     | R1  |
| L4  | C4     | R1  |
| L5  | C1     | R2  |
| L6  | C2     | R2  |
| ... | ...    | ... |
| L16 | C4     | R4  |

---

## Program Features

* Initializes all row and column pins as outputs.
* Demonstrates turning ON individual LEDs.
* Includes commented code for testing all 16 LEDs one by one.
* Displays multiple LED positions by changing row and column combinations.
* Uses `digitalWrite()` for direct hardware control.

---

## LED Matrix Layout

```text
      C1   C2   C3   C4
    +----+----+----+----+
R1  | L1 | L2 | L3 | L4 |
    +----+----+----+----+
R2  | L5 | L6 | L7 | L8 |
    +----+----+----+----+
R3  | L9 | L10| L11| L12|
    +----+----+----+----+
R4  | L13| L14| L15| L16|
    +----+----+----+----+
```

---

## Learning Outcomes

* Understanding LED matrix wiring
* Row and column multiplexing
* Using `pinMode()` and `digitalWrite()`
* Controlling multiple LEDs with fewer I/O pins
* Building simple LED animations and display patterns

---

## Folder Structure

```text
led_matrix/
├── led_matrix.ino
└── README.md
```

---

## Future Improvements

* Add multiplexing for smoother display.
* Create scrolling text and animations.
* Display characters and numbers.
* Control the matrix using arrays and loops instead of repeated code.
* Add user input using buttons or Serial Monitor.

---

## Author

**Rajan Nanda**

Arduino LED Matrix Project

