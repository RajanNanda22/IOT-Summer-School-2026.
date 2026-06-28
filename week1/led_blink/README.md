# LED Blink Project

## Project Title

Week 1 – LED Blink Project

## Project Overview

This project demonstrates a basic LED blink program using an Arduino. The LED turns ON and OFF repeatedly. The project also includes a serial blink counter and potentiometer-controlled blink speed.

## Hardware Required

* Arduino Uno
* USB cable
* Breadboard
* LED
* 220 Ω resistor
* 10 kΩ potentiometer
* Jumper wires

## Circuit Diagram Description

* Connect the LED anode (long leg) to Arduino digital pin 13 through a 220 Ω resistor.
* Connect the LED cathode (short leg) to GND.
* Connect one side of the potentiometer to 5V.
* Connect the other side of the potentiometer to GND.
* Connect the center pin (wiper) of the potentiometer to analog pin A0.

## How to Upload Code

1. Connect the Arduino board to the computer using a USB cable.
2. Open the Arduino IDE.
3. Open the `led_blink.ino` sketch.
4. Select **Tools → Board → Arduino Uno**.
5. Select the correct COM port under **Tools → Port**.
6. Click the **Verify** button to compile the code.
7. Click the **Upload** button.
8. Wait until the upload is complete.

## Expected Output

* The LED blinks continuously.
* The Serial Monitor displays the blink count.
* Rotating the potentiometer changes the LED blink speed.

## Troubleshooting Tips

1. Verify that the correct board and COM port are selected in the Arduino IDE.
2. Check that all jumper wire connections are secure and match the circuit description.
3. Ensure the LED polarity is correct (long leg to positive, short leg to GND).
4. Confirm that the potentiometer center pin is connected to analog pin A0.
5. If the code does not upload, reconnect the USB cable and try again.
