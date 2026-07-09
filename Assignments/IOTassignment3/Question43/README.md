# Smart Door Lock System with OTP Authentication

## Problem Statement

Design a secure IoT-based smart door lock system that authenticates users using a two-factor authentication mechanism. Users must first enter a valid 4-digit User ID through a keypad. The system then generates a random 6-digit One-Time Password (OTP) and sends it to the user's phone via an HC-05 Bluetooth module. Access is granted only if the correct OTP is entered within the specified time limit.

---

## Solution Approach

The system is built around an ESP32 and implements two-factor authentication using a keypad and Bluetooth communication. After the user enters a 4-digit ID, a random 6-digit OTP is generated and transmitted to a paired smartphone through the HC-05 Bluetooth module.

The user must enter the received OTP within **30 seconds**. If the entered OTP matches the generated OTP, a servo motor rotates to unlock the door for **3 seconds** before automatically locking again. If the OTP is incorrect or expires, access is denied, and the authentication process resets.

The LCD provides real-time user prompts and system status, while the Serial Monitor logs all authentication attempts for debugging and monitoring.

---

## Features

* 4-digit User ID authentication
* Random 6-digit OTP generation
* OTP transmission via HC-05 Bluetooth
* 30-second OTP expiration timer
* Servo-controlled automatic door lock
* Auto-lock after 3 seconds
* 16×2 I2C LCD user interface
* Authentication success/failure logging
* Automatic system reset after each attempt

---

## Hardware Components

* ESP32 DevKit V1
* HC-05 Bluetooth Module
* 4×4 Matrix Keypad
* SG90 Servo Motor
* 16×2 I2C LCD Display
* Breadboard
* Jumper Wires
* USB Cable

---

## Pin Connections

| Component      | ESP32 Pin           |
| -------------- | ------------------- |
| Servo Signal   | GPIO 18             |
| HC-05 TX       | GPIO 16 (RX2)       |
| HC-05 RX       | GPIO 17 (TX2)       |
| LCD SDA        | GPIO 21             |
| LCD SCL        | GPIO 22             |
| Keypad Rows    | GPIO 13, 12, 14, 27 |
| Keypad Columns | GPIO 26, 25, 33, 32 |

---

## Software Requirements

* Arduino IDE
* ESP32 Board Package
* ESP32Servo Library
* LiquidCrystal_I2C Library
* Keypad Library
* Wire Library

---

## Working Principle

1. The user enters a **4-digit User ID** using the keypad.
2. The ESP32 generates a **random 6-digit OTP**.
3. The OTP is sent to the paired smartphone via the HC-05 Bluetooth module.
4. The user enters the received OTP using the keypad.
5. If the OTP matches within **30 seconds**, the servo unlocks the door.
6. The door remains unlocked for **3 seconds** before automatically locking again.
7. All successful and failed authentication attempts are logged to the Serial Monitor.
8. The system resets and waits for the next user.

---

## Sample Serial Output

```text
System Ready

ID Entered: 1234
OTP GENERATED: 582641
Enter OTP:
******
OTP ENTERED: 582641
ACCESS GRANTED - Door Unlocked
----------------------
LOG: SUCCESS ENTRY
```

### Failed Authentication

```text
System Ready

ID Entered: 1234
OTP GENERATED: 582641
Enter OTP:
******
OTP ENTERED: 111111
ACCESS DENIED
----------------------
LOG: FAILED ENTRY
```

### OTP Timeout

```text
System Ready

ID Entered: 1234
OTP GENERATED: 582641
OTP EXPIRED!
----------------------
LOG: FAILED ENTRY
```

---

## Future Improvements

* Store multiple authorized users in EEPROM or flash memory.
* Encrypt Bluetooth communication for enhanced security.
* Integrate fingerprint or RFID authentication.
* Send OTP through SMS or email using cloud services.
* Add Wi-Fi connectivity for remote monitoring and access logs.
* Store authentication history in a cloud database.

---

## Author

**Rajan Nanda**
