# Smart Street Light (LDR + PIR)

## Objective

Develop an intelligent street light system using an LDR and PIR sensor.

### Features

- During daylight, the street light remains OFF.
- At night, motion detection becomes active.
- Motion detected at night turns the LED ON at full brightness.
- If no motion is detected for 30 seconds, the LED dims to 20% brightness.
- Every event is logged to the Serial Monitor with a timestamp.

---

## Components Required

- Arduino Uno
- LDR (Photoresistor)
- 10kΩ Resistor
- PIR Motion Sensor (HC-SR501)
- LED
- 220Ω Resistor
- Breadboard
- Jumper Wires

---

## Connections

| Component | Arduino Pin |
|-----------|-------------|
| LDR Output | A0 |
| PIR Output | D2 |
| LED (+) | D9 (PWM) |
| LED (-) | GND |

---

## Working

### Day Mode

- LDR value is above the threshold.
- LED remains OFF.
- Motion sensor is ignored.

### Night Mode

- LDR value falls below the threshold.
- Motion detection becomes active.

### Motion Detected

- LED turns ON at full brightness (100% PWM).
- Timer starts.

### No Motion

- If no motion occurs for 30 seconds,
- LED brightness is reduced to 20%.

---

## Sample Serial Output

```
[00:00:02] EVENT: Night detected - Motion Detection Enabled
[00:00:07] EVENT: Motion detected - LED ON (100%)
[00:00:38] EVENT: No motion for 30 seconds - LED Dimmed (20%)
[00:10:12] EVENT: Daylight detected - Street Light OFF
```

---

## Folder Structure

```
week3/
├── smart_street_light/
│   ├── smart_street_light.ino
│   └── README.md
└── schematics/
    └── smart_street_light_circuit.png
```

---

## Expected Result

- Daylight → LED OFF
- Night → Motion detection enabled
- Motion → LED ON at 100% brightness
- No motion for 30 seconds → LED dims to 20%
- All events logged to the Serial Monitor with timestamps
- Circuit diagram saved in `/week3/schematics/`
