# Servo Motor Sweep using Potentiometer and Push Button

## Objective

Control an SG90 servo motor using a potentiometer. The potentiometer position is mapped from 0–1023 to a servo angle of 0°–180°. The current angle is displayed on the Serial Monitor. Pressing the push button makes the servo perform one complete sweep from 0° to 180° and back to 0°.

---

## Components Required

- Arduino Uno
- SG90 Servo Motor
- 10kΩ Potentiometer
- Push Button
- Breadboard
- Jumper Wires

---

## Connections

| Component | Arduino Pin |
|-----------|-------------|
| Servo Signal | D9 |
| Servo VCC | 5V |
| Servo GND | GND |
| Potentiometer Middle Pin | A0 |
| Potentiometer Ends | 5V and GND |
| Push Button | D2 |
| Push Button Other Side | GND |

---

## Working

1. The Arduino reads the potentiometer value.
2. The value is mapped from 0–1023 to 0°–180°.
3. The servo rotates to the mapped angle.
4. The current angle is displayed on the Serial Monitor.
5. When the push button is pressed, the servo performs a full sweep from 0° to 180° and returns to 0°.

---

## Sample Serial Output

```
Servo Angle: 0 degrees
Servo Angle: 28 degrees
Servo Angle: 67 degrees
Servo Angle: 102 degrees
Servo Angle: 145 degrees
Servo Angle: 180 degrees
```

---

## Expected Result

- Servo follows the potentiometer position.
- Angle is displayed on the Serial Monitor.
- Pressing the button performs one complete servo sweep (0° → 180° → 0°).
