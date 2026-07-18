# 🏭 SafeZone IoT - Intelligent Industrial Safety & Predictive Risk Monitoring System

![ESP32](https://img.shields.io/badge/ESP32-IoT-blue)
![Arduino](https://img.shields.io/badge/Arduino-C%2B%2B-green)
![MQTT](https://img.shields.io/badge/MQTT-HiveMQ-orange)
![License](https://img.shields.io/badge/License-MIT-yellow)

## 📖 Overview

**SafeZone IoT** is an Industrial Internet of Things (IIoT) project designed to improve workplace safety through real-time environmental monitoring and predictive risk detection.

The system continuously monitors hazardous conditions using multiple sensors connected to an ESP32 and communicates with an MQTT broker. Based on the detected risk level, the system automatically controls warning LEDs, a buzzer, and a relay to help prevent industrial accidents.

---

# 🎯 Project Objectives

- Monitor industrial environmental conditions in real time
- Detect gas leaks
- Detect fire hazards
- Monitor temperature and humidity
- Detect human motion
- Provide automatic warning indications
- Control industrial equipment using relay
- Communicate sensor data through MQTT
- Enable predictive risk monitoring

---

# ⚙ Hardware Used

| Component | Quantity |
|-----------|----------|
| ESP32 Dev Module | 1 |
| MQ-2 Gas Sensor | 1 |
| DHT22 Temperature & Humidity Sensor | 1 |
| Flame Sensor | 1 |
| PIR Motion Sensor | 1 |
| Relay Module | 1 |
| Green LED | 1 |
| Yellow LED | 1 |
| Red LED | 1 |
| Active Buzzer | 1 |

---

# 🛠 Software Used

- Arduino IDE
- ESP32 Board Package
- MQTT (HiveMQ Broker)
- ArduinoJson Library
- PubSubClient Library
- DHT Sensor Library
- Wokwi Simulator
- GitHub

---

# 📡 Communication Protocol

- Wi-Fi
- MQTT

Broker

```
broker.hivemq.com
```

Port

```
1883
```

---

# MQTT Topics

## Publish

```
factory/section1/sensors
```

Example JSON

```json
{
  "gas_ppm": 520,
  "temperature": 31.5,
  "humidity": 58.7,
  "flame": false,
  "motion": true
}
```

---

## Subscribe

```
factory/section1/control
```

Example Control Message

```json
{
  "led":"red",
  "buzzer":true,
  "relay":false
}
```

---

# 🔌 Pin Configuration

| Device | ESP32 Pin |
|---------|-----------|
| DHT22 | GPIO15 |
| MQ2 Gas Sensor | GPIO34 |
| Flame Sensor | GPIO27 |
| PIR Sensor | GPIO26 |
| Green LED | GPIO32 |
| Yellow LED | GPIO14 |
| Red LED | GPIO12 |
| Relay | GPIO25 |
| Buzzer | GPIO33 |

---

# 🚦 Working Principle

1. ESP32 connects to Wi-Fi.
2. ESP32 connects to the MQTT broker.
3. Every 2 seconds:
   - Reads gas concentration
   - Reads temperature
   - Reads humidity
   - Detects flame
   - Detects motion
4. Sensor data is published as a JSON message.
5. A monitoring application analyzes the received data.
6. Based on the risk level, a control message is sent back to the ESP32.
7. ESP32 activates:
   - Green LED (Safe)
   - Yellow LED (Warning)
   - Red LED (Danger)
   - Buzzer
   - Relay

---

# 📂 Project Structure

```
SafeZone-IoT
│
├── src/
│   └── main.ino
│
├── images/
│   ├── circuit.png
│   ├── dashboard.png
│   └── block-diagram.png
│
├── docs/
│   ├── Project_Report.pdf
│   └── Presentation.pdf
│
├── wokwi/
│   └── diagram.json
│
├── README.md
├── LICENSE
└── .gitignore
```

---

# 📈 System Workflow

```
Sensors
   │
   ▼
ESP32
   │
Wi-Fi
   │
MQTT Broker
   │
Risk Analysis
   │
Control Message
   │
ESP32
   │
Relay + LEDs + Buzzer
```

---

# 🚨 Risk Levels

## 🟢 Safe

- Green LED ON
- Relay ON
- Buzzer OFF

---

## 🟡 Warning

- Yellow LED ON
- Relay ON
- Buzzer OFF

---

## 🔴 Danger

- Red LED ON
- Relay OFF
- Buzzer ON

---

# 📷 Simulation

The complete project can be simulated using **Wokwi**.

Components:

- ESP32
- MQ2
- DHT22
- Flame Sensor
- PIR Sensor
- LEDs
- Relay
- Buzzer

---

# 📚 Libraries Required

Install the following libraries from the Arduino Library Manager:

- WiFi
- PubSubClient
- ArduinoJson
- DHT Sensor Library

---

# 🚀 Future Improvements

- Multi-zone industrial monitoring
- Cloud dashboard
- Node-RED integration
- Blynk dashboard
- Firebase support
- Email notifications
- SMS alerts
- AI-based predictive maintenance
- Historical data logging
- Mobile application

---

# 👨‍💻 Author

**Rajan Nanda**

Electrical Engineering Student

Industrial IoT Enthusiast

---

# 📄 License

This project is licensed under the MIT License.

---

# ⭐ If you found this project useful

Give this repository a ⭐ on GitHub.
