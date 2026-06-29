# State Machine Implementation – Arduino Vending Machine

## Overview

This project implements a simple vending machine using the **Finite State Machine (FSM)** concept in Arduino. The vending machine has four operating states and changes between them based on user inputs from three push buttons.

Three LEDs indicate the current state, while every state transition is displayed on the Serial Monitor. The Arduino code also includes a comment block documenting the complete state transition diagram.

---

## Components Required

* Arduino Uno (or compatible board)
* 3 × LEDs
* 3 × 220Ω Resistors
* 3 × Push Buttons
* 3 × 10kΩ Resistors (or use `INPUT_PULLUP`)
* Breadboard
* Jumper Wires

---

## Pin Configuration

| Component          | Arduino Pin |
| ------------------ | ----------- |
| State LED 1        | D2          |
| State LED 2        | D3          |
| State LED 3        | D4          |
| Insert Coin Button | D5          |
| Select Item Button | D6          |
| Cancel Button      | D7          |

---

## State Definitions

| State             | Description                                                                        |
| ----------------- | ---------------------------------------------------------------------------------- |
| **IDLE**          | Waiting for a customer to insert a coin.                                           |
| **COIN_INSERTED** | Coin has been inserted and the system is waiting for an item selection.            |
| **ITEM_SELECTED** | An item has been selected and is ready for dispensing.                             |
| **DISPENSING**    | The selected item is dispensed, after which the machine returns to the IDLE state. |

---

## State Transition Diagram

```text
                 Insert Coin
      +----------------------------+
      |                            |
      v                            |
+-------------+               +----------------+
|    IDLE     | ------------> | COIN_INSERTED |
+-------------+               +----------------+
       ^                              |
       |                              | Select Item
       |                              v
       |                      +----------------+
       |                      | ITEM_SELECTED |
       |                      +----------------+
       |                              |
       |                              | Dispense
       |                              v
       |                      +----------------+
       +----------------------|  DISPENSING   |
              Complete         +----------------+

Cancel button:
COIN_INSERTED → IDLE
ITEM_SELECTED → IDLE
```

---

## Working

1. The system starts in the **IDLE** state.
2. Press **Insert Coin** to move to **COIN_INSERTED**.
3. Press **Select Item** to move to **ITEM_SELECTED**.
4. The machine automatically enters **DISPENSING**.
5. After dispensing, it returns to **IDLE**.
6. Pressing **Cancel** during **COIN_INSERTED** or **ITEM_SELECTED** immediately returns the machine to **IDLE**.
7. LEDs indicate the active state, and every transition is printed on the Serial Monitor.

---

## Example Serial Output

```text
Vending Machine Started

Current State : IDLE

Transition:
IDLE -> COIN_INSERTED

Transition:
COIN_INSERTED -> ITEM_SELECTED

Transition:
ITEM_SELECTED -> DISPENSING

Transition:
DISPENSING -> IDLE

Transition:
COIN_INSERTED -> IDLE (Cancel)
```

---

## Features

* Four-state Finite State Machine (FSM)
* Three push-button inputs
* LED indication of current state
* Serial Monitor logging of every state transition
* Cancel operation supported
* Well-documented state transition diagram included in the source code

---

## Learning Outcomes

* Understanding Finite State Machines (FSM)
* Implementing state transitions in Arduino
* Reading multiple digital inputs
* Controlling LEDs based on system state
* Using Serial Monitor for debugging
* Designing event-driven embedded systems

---

## Folder Structure

```text
week2/
└── state_machine_vending/
    ├── state_machine_vending.ino
    └── README.md
```

---

## Author

**Rajan Nanda**

Arduino Programming – Week 2 Assignment
