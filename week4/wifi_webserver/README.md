# Wi-Fi Temperature Monitor (ESP8266 / ESP32)

## Objective

Create a web server using an ESP8266 or ESP32 that displays live DHT11 sensor readings and allows LED control through a web browser.

---

## Features

- Connects to a Wi-Fi network
- Displays Temperature
- Displays Humidity
- Auto-refresh every 10 seconds
- Toggle onboard LED
- Shows device uptime
- Accessible using the ESP's local IP address

---

## Components

- ESP8266 or ESP32
- DHT11 Sensor
- Breadboard
- Jumper Wires
- USB Cable

---

## Wiring

### DHT11

| DHT11 | ESP32 |
|--------|--------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO4 |

### LED

Uses the onboard LED connected to:

- ESP32 → GPIO2
- ESP8266 → Built-in LED (may be active LOW depending on the board)

---

## Setup

1. Open `secrets.h`.
2. Enter your Wi-Fi credentials.

```cpp
#define WIFI_SSID "YourWiFi"
#define WIFI_PASSWORD "YourPassword"
```

3. Upload the sketch.
4. Open the Serial Monitor.
5. Note the local IP address displayed.
6. Enter the IP address into a web browser.

Example:

```
http://192.168.1.105
```

---

## Web Page Features

- Temperature (°C)
- Humidity (%)
- LED Status
- Toggle LED Button
- Device Uptime
- Auto-refresh every 10 seconds

---

## Folder Structure

```
week4/
└── wifi_webserver/
    ├── wifi_webserver.ino
    ├── secrets.h
    ├── .gitignore
    ├── README.md
    └── screenshots/
        └── webpage_screenshot.png
```

---

## Screenshot

Place the working webpage screenshot inside:

```
week4/wifi_webserver/screenshots/
```

Example filename:

```
webpage_screenshot.png
```

---

## Learning Outcomes

- Wi-Fi networking with ESP8266/ESP32
- HTTP web server
- HTML page generation
- Reading DHT11 sensor data
- GPIO control from a web browser
- Device uptime monitoring
- Auto-refresh using HTML meta tag

---

## Author

Rajan Nanda 
