# Serial Command Interface using Arduino

## Overview

This project demonstrates how to control Arduino hardware through commands entered in the Serial Monitor. The Arduino continuously listens for user input and performs the corresponding action.

Supported commands include turning the built-in LED on or off, blinking it a specified number of times, displaying the current pin status, and resetting the blink counter. Invalid commands are detected and an error message is displayed.

---

## Components Required

* Arduino Uno (or compatible board)
* USB Cable
* Arduino IDE
* Built-in LED (Pin 13)

---

## Supported Commands

| Command         | Description                                      |
| --------------- | ------------------------------------------------ |
| `LED_ON`        | Turns the built-in LED ON                        |
| `LED_OFF`       | Turns the built-in LED OFF                       |
| `BLINK_X`       | Blinks the LED **X** times (1–9)                 |
| `STATUS`        | Displays the current LED state and blink counter |
| `RESET`         | Resets the blink counter                         |
| Invalid Command | Prints `ERROR: Unknown command`                  |

---

## Working

1. Upload the program to the Arduino.
2. Open the Serial Monitor.
3. Set the baud rate to match the program (for example, **9600 baud**).
4. Enter one of the supported commands and press **Send**.
5. The Arduino processes the command and performs the requested action.
6. If an unsupported command is entered, the program prints:

```text
ERROR: Unknown command
```

---

## Example Commands

```text
LED_ON
LED_OFF
BLINK_3
BLINK_7
STATUS
RESET
HELLO
```

---

## Example Serial Output

```text
Command: LED_ON
LED is ON

Command: BLINK_3
Blinking LED 3 times...

Command: STATUS
LED State : OFF
Blink Counter : 3

Command: RESET
Blink Counter Reset

Command: TEST
ERROR: Unknown command
```

---

## Input Validation

* Accepts only the predefined commands.
* `BLINK_X` supports values from **1** to **9**.
* Any invalid or unsupported command displays:

```text
ERROR: Unknown command
```

This prevents unexpected behavior and improves program reliability.

---

## Learning Outcomes

* Serial communication using `Serial.begin()`
* Reading user input with `Serial.readString()`
* Comparing strings in Arduino
* Controlling digital outputs
* Implementing command-based interfaces
* Input validation and error handling
* Maintaining program state with variables

---

## Folder Structure

```text
week2/
└── serial_command_interface/
    ├── serial_command_interface.ino
    └── README.md
```

---

## Author

**Rajan Nanda**

Arduino Programming – Week 2 Assignment
