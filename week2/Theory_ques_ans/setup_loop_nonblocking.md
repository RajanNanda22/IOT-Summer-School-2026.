# Q20. setup() and loop() in Arduino

## setup() Function

The `setup()` function runs **once** when the Arduino starts or resets. It is used to initialize settings such as pin modes, serial communication, and sensors.

### Example uses:

* `pinMode()` configuration
* `Serial.begin()`
* Initializing libraries or sensors

---

## loop() Function

The `loop()` function runs **continuously** after `setup()` finishes. It contains the main program logic and repeats forever.

### Example uses:

* Reading sensors
* Controlling LEDs or motors
* Sending data to cloud or serial monitor

---

## Effect of Long delay() in loop()

If a long `delay()` is used inside the `loop()` function:

* The Arduino **stops executing other code temporarily**
* Sensor readings are delayed
* Button presses may be missed
* System becomes **unresponsive**

### Example Problem:

If `delay(5000)` is used, the Arduino cannot read sensors or inputs for 5 seconds.

---

## Impact on Sensor Responsiveness

* Slow reaction to real-world changes
* Missed interrupts or button presses
* Poor performance in real-time IoT systems

---

## Non-blocking Alternative

Instead of `delay()`, we use **non-blocking timing** with:

### 1. millis() function

* Tracks time without stopping code execution
* Allows multiple tasks to run simultaneously

### 2. Example concept:

* Compare current time using `millis()`
* Execute actions only when required time has passed

### Benefits:

* Real-time responsiveness
* Multiple sensors can be handled together
* Better for IoT systems and multitasking

---

## Summary

* `setup()` runs once for initialization
* `loop()` runs repeatedly for main logic
* Long `delay()` blocks execution
* `millis()` enables non-blocking programming
