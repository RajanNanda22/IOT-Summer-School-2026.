# Relay-Controlled AC Device Simulation

## Objective

Simulate an AC appliance using a relay (or an LED for safe testing). A DHT11 temperature sensor automatically controls the relay using hysteresis. A push button provides manual override, and every relay state change is logged to the Serial Monitor along with the current temperature.

---

## Components Required

- Arduino Uno
- DHT11 Temperature and Humidity Sensor
- Relay Module (or LED with 220Ω resistor for simulation)
- Push Button
- Breadboard
- Jumper Wires

---

## Connections

| Component | Arduino Pin |
|-----------|-------------|
| DHT11 Data | D2 |
| Relay IN / LED | D8 |
| Relay VCC | 5V |
| Relay GND | GND |
| Push Button | D7 |
| Other Button Terminal | GND |

> The push button uses `INPUT_PULLUP`, so no external pull-up resistor is required.

---

## Working

1. Read temperature from the DHT11 sensor every 2 seconds.
2. Turn the relay ON when the temperature rises above **32°C**.
3. Keep the relay ON until the temperature falls below **28°C**.
4. The 28°C–32°C range creates **hysteresis**, preventing rapid switching.
5. Press the push button to manually toggle the relay ON or OFF.
6. Every relay state change is logged to the Serial Monitor with the current temperature.

---

## Hysteresis Logic

| Temperature | Relay State |
|-------------|-------------|
| > 32°C | ON |
| 28°C – 32°C | Previous State |
| < 28°C | OFF |

---

## Sample Serial Output

```
Relay ON | Temperature: 33.2 °C
Manual Override -> Relay OFF | Temp: 33.1 °C
Relay OFF | Temperature: 33.1 °C
Relay ON | Temperature: 34.0 °C
Relay OFF | Temperature: 27.5 °C
```

---

## Expected Result

- Relay (or LED) turns ON automatically when temperature exceeds **32°C**.
- Relay remains ON until the temperature drops below **28°C**.
- Manual override button toggles the relay state at any time.
- All relay state changes are displayed on the Serial Monitor together with the temperature reading.
