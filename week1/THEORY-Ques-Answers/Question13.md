# Arduino UNO Pin Types

## 1. Digital Input

**Description:**
Digital input pins read only two states: **HIGH (1)** or **LOW (0)**.

**Example:**
Push button connected to digital pin D2.

**IoT Use Case:**
Detecting whether a door is open or closed using a magnetic reed switch in a smart home.

---

## 2. Digital Output

**Description:**
Digital output pins send HIGH or LOW signals to control external devices.

**Example:**
LED connected to digital pin D13.

**IoT Use Case:**
Turning a relay ON or OFF to control home appliances remotely.

---

## 3. Analog Input

**Description:**
Analog input pins measure varying voltage levels (0–5 V) and convert them into digital values (0–1023).

**Available Pins:**
A0–A5

**Example:**
Potentiometer connected to A0.

**IoT Use Case:**
Reading data from a temperature, light, or soil moisture sensor.

---

## 4. PWM Output

**Description:**
PWM (Pulse Width Modulation) pins simulate analog output by rapidly switching between HIGH and LOW.

**Available Pins:**
D3, D5, D6, D9, D10, D11

**Example:**
Controlling LED brightness.

**IoT Use Case:**
Adjusting the speed of a DC motor or controlling the brightness of smart lighting.

---

## 5. I2C / SPI Pins

### I2C (Inter-Integrated Circuit)

**Pins:**

* SDA → A4
* SCL → A5

**Example:**
Connecting an OLED display or environmental sensor.

**IoT Use Case:**
Reading data from multiple sensors using only two communication wires.

### SPI (Serial Peripheral Interface)

**Pins:**

* MOSI → D11
* MISO → D12
* SCK → D13
* SS → D10

**Example:**
Connecting an SD card module or Ethernet module.

**IoT Use Case:**
Storing sensor data on an SD card or communicating with high-speed peripherals.
