# 4-Layer IoT Architecture

```
+----------------------------------------+
|        Application Layer               |
| Example: Mobile App / Web Dashboard    |
+----------------------------------------+
                 ↑
+----------------------------------------+
|         Processing Layer               |
| Example: Cloud Server (AWS, Azure)     |
+----------------------------------------+
                 ↑
+----------------------------------------+
|          Network Layer                 |
| Example: Wi-Fi / MQTT                  |
+----------------------------------------+
                 ↑
+----------------------------------------+
|         Perception Layer               |
| Example: Arduino + Temperature Sensor  |
+----------------------------------------+
```

## Layer Examples

* **Perception Layer:** Arduino Uno with a temperature sensor (e.g., DHT11)
* **Network Layer:** Wi-Fi using ESP8266 or MQTT protocol
* **Processing Layer:** Cloud platform such as AWS IoT or Azure IoT Hub
* **Application Layer:** Mobile app or web dashboard for monitoring and control
