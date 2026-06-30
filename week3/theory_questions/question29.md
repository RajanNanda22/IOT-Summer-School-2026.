# Q29. Sensor Calibration in IoT Systems

## What is Sensor Calibration?

Sensor calibration is the process of comparing a sensor's readings with known reference values and adjusting the measurements to improve accuracy. Calibration helps reduce errors caused by manufacturing differences, aging, and environmental conditions.

## Why is Calibration Important in IoT Systems?

Calibration is important because it:

- Improves measurement accuracy.
- Provides reliable and consistent sensor data.
- Reduces errors in monitoring and automation.
- Increases the reliability of IoT devices for real-world applications.

## Calibrating an Analog Soil Moisture Sensor

An analog soil moisture sensor outputs different analog values depending on the moisture level in the soil. To convert these values into an accurate moisture percentage, a two-point calibration is commonly used.

### Two-Point Calibration Method

1. **Dry Calibration**
   - Keep the sensor completely dry (in air).
   - Record the analog reading.
   - Example: `Dry Value = 850`

2. **Wet Calibration**
   - Place the sensor in fully saturated soil or water.
   - Record the analog reading.
   - Example: `Wet Value = 350`

3. **Convert to Percentage**

Use the Arduino `map()` function to convert the sensor value into a percentage:

```cpp
int moisturePercent = map(sensorValue, 850, 350, 0, 100);
```

- `0%` represents completely dry soil.
- `100%` represents fully wet soil.

## Conclusion

Two-point calibration improves the accuracy of soil moisture measurements by using known dry and wet reference values. This ensures reliable data for IoT applications such as smart irrigation and precision agriculture.
