# MQTT Sensor Publisher (ESP32)

## Objective

Publish DHT11 sensor readings to a public MQTT broker every 5 seconds and receive LED control commands through an MQTT subscription.

---

## Components Required

- ESP32 Development Board
- DHT11 Sensor
- Breadboard
- Jumper Wires
- USB Cable

---

## Libraries

- WiFi
- PubSubClient
- DHT Sensor Library

---

## Wiring

| DHT11 | ESP32 |
|--------|-------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO4 |

Onboard LED:

GPIO2

---

## MQTT Broker

Default:

```
broker.hivemq.com
```

Alternative:

```
test.mosquitto.org
```

Port:

```
1883
```

---

## Topics

Replace **yourname** with your own name.

### Publish

```
iitjammu/summer26/rajan/temperature
```

```
iitjammu/summer26/rajan/humidity
```

### Subscribe

```
iitjammu/summer26/rajan/led_control
```

---

## JSON Message Format

Temperature

```json
{
  "value": 28.5,
  "unit": "C",
  "ts": 1234567890
}
```

Humidity

```json
{
  "value": 65.2,
  "unit": "%",
  "ts": 1234567890
}
```

---

## LED Control

Publish the following messages to:

```
iitjammu/summer26/rajan/led_control
```

| Message | Action |
|----------|--------|
| ON | LED ON |
| OFF | LED OFF |

---

## Testing with MQTT Explorer

1. Install MQTT Explorer.
2. Connect to:

```
broker.hivemq.com
```

Port:

```
1883
```

3. Subscribe to:

```
iitjammu/summer26/rajan/#
```

4. Observe incoming JSON messages every 5 seconds.
5. Publish `ON` or `OFF` to the `led_control` topic and verify the onboard LED changes state.

---

## Folder Structure

```
week4/
└── mqtt_sensor_publisher/
    ├── mqtt_sensor_publisher.ino
    ├── secrets.h
    ├── .gitignore
    ├── README.md
    └── screenshots/
        └── mqtt_explorer_messages.png
```

---

## Screenshot

Upload a screenshot showing:

- Temperature topic messages
- Humidity topic messages
- JSON payload
- MQTT Explorer or MQTT.fx connected successfully

Save it as:

```
week4/mqtt_sensor_publisher/screenshots/mqtt_explorer_messages.png
```

---

## Learning Outcomes

- ESP32 Wi-Fi connectivity
- MQTT publish and subscribe
- JSON payload creation
- Sensor data transmission
- Remote LED control using MQTT
- Public MQTT broker usage

---

## Author

Rajan Nanda 
