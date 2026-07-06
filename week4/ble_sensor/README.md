# Bluetooth Sensor Dashboard (ESP32 BLE)

## Objective

Use ESP32 Bluetooth Low Energy (BLE) to broadcast DHT11 sensor readings every 3 seconds. A BLE scanner app such as **nRF Connect** or **LightBlue** can read the sensor values through GATT characteristics.

---

# Components Required

- ESP32 Development Board
- DHT11 Temperature & Humidity Sensor
- Jumper Wires
- USB Cable

---

# Wiring

| DHT11 | ESP32 |
|--------|--------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO4 |

---

# BLE Service

**Service UUID**

```
12345678-1234-1234-1234-123456789000
```

---

# GATT Characteristics

| Characteristic | UUID | Property |
|---------------|----------------------------------------|----------------|
| Temperature | 12345678-1234-1234-1234-123456789001 | Read, Notify |
| Humidity | 12345678-1234-1234-1234-123456789002 | Read, Notify |
| Timestamp | 12345678-1234-1234-1234-123456789003 | Read, Notify |

Each characteristic includes:

- Client Characteristic Configuration Descriptor (CCCD - 0x2902)
- User Description Descriptor (0x2901)

---

# Data Broadcast

Every **3 seconds**, the ESP32 updates:

- Temperature
- Humidity
- Timestamp (seconds since boot)

Example:

```
Temperature : 28.5 C
Humidity    : 63.0 %
Timestamp   : 18 sec
```

---

# Testing

## Using nRF Connect

1. Upload the sketch.
2. Open nRF Connect.
3. Scan for devices.
4. Connect to:

```
ESP32 BLE Sensor
```

5. Open the service.
6. Enable Notifications.
7. Observe live sensor updates every 3 seconds.

---

## Using LightBlue

1. Scan for BLE devices.
2. Connect to **ESP32 BLE Sensor**.
3. Open each characteristic.
4. Read or subscribe to notifications.

---

# Features

- ESP32 BLE Server
- Custom GATT Service
- Three Characteristics
- Notify Support
- Read Support
- BLE Descriptors
- DHT11 Sensor Integration
- 3-second Update Interval

---

# Folder Structure

```
week4/
└── ble_sensor/
    ├── ble_sensor.ino
    └── README.md
```

---

# Author

Rajan Nanda
