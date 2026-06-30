# Multi-Sensor Data Logger

## Objective

Read data from three sensors simultaneously and display the readings in a structured format every 5 seconds.

## Sensors Used

- DHT11 Temperature & Humidity Sensor
- LDR (Light Sensor)
- HC-SR04 Ultrasonic Distance Sensor

---

## Components Required

- Arduino Uno
- DHT11 Sensor
- LDR
- 10kΩ Resistor
- HC-SR04 Ultrasonic Sensor
- Breadboard
- Jumper Wires

---

## Connections

### DHT11

| Sensor Pin | Arduino |
|------------|----------|
| DATA | D2 |
| VCC | 5V |
| GND | GND |

### LDR

| Component | Arduino |
|-----------|----------|
| LDR Output | A0 |

### HC-SR04

| Sensor Pin | Arduino |
|------------|----------|
| Trig | D8 |
| Echo | D9 |
| VCC | 5V |
| GND | GND |

---

## Working

1. Reads temperature and humidity from the DHT11.
2. Reads the raw LDR value (0–1023).
3. Converts the LDR value into a percentage (0–100%).
4. Classifies the light level as:
   - Bright
   - Normal
   - Dark
5. Measures the distance using the HC-SR04 ultrasonic sensor.
6. Displays all sensor readings in a structured format every 5 seconds.

---

## Sample Serial Output

```
=== SENSOR LOG ===
Time      : 5000 ms
Temp      : 28.5 C | Humidity: 65%
Light     : 73% (Bright)
Distance  : 42 cm
==================
```

---

## Expected Result

- Sensor values update every 5 seconds.
- Temperature and humidity are displayed.
- Light level is shown as both a percentage and a status (Bright, Normal, or Dark).
- Distance is displayed in centimeters.
- Output is formatted for easy reading in the Serial Monitor.
