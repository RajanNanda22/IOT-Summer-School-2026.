/*
  Project - Environmental Monitoring Station
  Name - Rajan Nanda
  Date - 6-7-2026
  
  Reads temperature and humidity from DHT11 every 2 seconds.
  Displays data in CSV format:
  timestamp,temp_C,temp_F,humidity

  Red LED  -> Temperature > 35°C OR Humidity > 80%
  Green LED -> Normal Conditions
*/

#include <DHT.h>

// Pin Definitions
#define DHTPIN 2
#define DHTTYPE DHT11

#define RED_LED 8
#define GREEN_LED 9

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // CSV Header
  Serial.println("timestamp,temp_C,temp_F,humidity");
}

void loop() {

  float humidity = dht.readHumidity();
  float tempC = dht.readTemperature();

  if (isnan(humidity) || isnan(tempC)) {
    Serial.println("Sensor Error");
    delay(2000);
    return;
  }

  float tempF = tempC * 9.0 / 5.0 + 32.0;

  // Timestamp (milliseconds)
  unsigned long timestamp = millis();

  // CSV Output
  Serial.print(timestamp);
  Serial.print(",");
  Serial.print(tempC);
  Serial.print(",");
  Serial.print(tempF);
  Serial.print(",");
  Serial.println(humidity);

  // LED Control
  if (tempC > 35 || humidity > 80) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }
  else {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  delay(2000);
}
