# DC Motor Speed Control with L298N

## Objective

Control a DC motor using an L298N motor driver. A potentiometer adjusts the motor speed (PWM 0–255), one push button changes the motor direction (Forward/Reverse), and another push button starts or stops the motor. The Serial Monitor displays the motor direction, speed percentage, and current state.

---

## Components Required

- Arduino Uno
- L298N Motor Driver Module
- DC Motor
- 10kΩ Potentiometer
- 2 Push Buttons
- Breadboard
- Jumper Wires
- External Motor Power Supply (if required)

---

## Connections

| Component | Arduino Pin |
|-----------|-------------|
| ENA | D9 (PWM) |
| IN1 | D7 |
| IN2 | D8 |
| Potentiometer Middle Pin | A0 |
| Potentiometer Ends | 5V and GND |
| Direction Button | D2 |
| Start/Stop Button | D3 |
| Buttons Other Side | GND |

---

## Working

1. The potentiometer controls the PWM value (0–255).
2. PWM determines the motor speed.
3. The Direction button toggles between Forward and Reverse.
4. The Start/Stop button turns the motor on or off.
5. The Serial Monitor continuously displays:
   - Direction
   - Speed (0–100%)
   - Motor State

---

## Sample Serial Output

```
Direction: Forward | Speed: 15% | State: Running
Direction: Forward | Speed: 48% | State: Running
Direction: Reverse | Speed: 48% | State: Running
Direction: Reverse | Speed: 72% | State: Running
Direction: Reverse | Speed: 72% | State: Stopped
Direction: Forward | Speed: 90% | State: Running
```

---

## Expected Result

- Potentiometer smoothly controls motor speed.
- Direction button switches between Forward and Reverse.
- Start/Stop button enables or disables the motor.
- Serial Monitor displays the current direction, speed percentage, and motor state.
