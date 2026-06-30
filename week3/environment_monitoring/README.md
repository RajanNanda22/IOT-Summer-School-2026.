# Environmental Monitoring Station (DHT11)

## Objective

Build a mini weather station using the DHT11 sensor that:

- Reads temperature in Celsius and Fahrenheit
- Reads humidity
- Updates every 2 seconds
- Prints data in CSV format
- Turns ON Red LED if:
  - Temperature > 35°C
  - Humidity > 80%
- Turns ON Green LED when conditions are normal

---

## Components

- Arduino Uno
- DHT11 Sensor
- Red LED
- Green LED
- 220Ω Resistors
- Breadboard
- Jumper Wires

---

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| DHT11 Data | D2 |
| Red LED | D8 |
| Green LED | D9 |

---

## Serial Output Format

timestamp,temp_C,temp_F,humidity

Example:

0,28.5,83.3,60
2,28.6,83.5,61
4,28.4,83.1,60

---

## Library Used

**DHT sensor library by Adafruit**

Version:
```
1.4.6
```

Also install:

```
Adafruit Unified Sensor
```

---

## Author

Rj Rajan
