# Q19. Difference Between analogRead() and analogWrite()

## Difference Between analogRead() and analogWrite()

| Feature           | analogRead()                                   | analogWrite()                                                        |
| ----------------- | ---------------------------------------------- | -------------------------------------------------------------------- |
| **Purpose**       | Reads an analog voltage from a sensor.         | Outputs a PWM signal to simulate an analog output.                   |
| **Pins Used**     | Analog input pins (A0–A5 on Arduino UNO).      | PWM pins (3, 5, 6, 9, 10, 11 on Arduino UNO).                        |
| **Return/Output** | Returns a value between **0 and 1023**.        | Accepts a value between **0 and 255** to control the PWM duty cycle. |
| **Example**       | Reading a potentiometer or temperature sensor. | Controlling LED brightness or motor speed.                           |

## What is PWM?

**PWM (Pulse Width Modulation)** is a technique that rapidly switches a digital output between HIGH and LOW. By changing the percentage of time the signal stays HIGH (called the duty cycle), Arduino can simulate different analog output levels.

### Why is PWM used?

PWM is used when variable output is needed, such as:

* Adjusting LED brightness
* Controlling DC motor speed
* Driving buzzers or fans with different power levels

## Practical IoT Examples

### analogRead()

A smart irrigation system uses a **soil moisture sensor** connected to an analog input pin. The Arduino reads the sensor value using `analogRead()` and automatically turns on a water pump when the soil is dry.

### analogWrite()

A smart street lighting system uses `analogWrite()` to adjust **LED brightness** based on ambient light, reducing power consumption during the night.
