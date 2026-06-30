/*
  Q24 - Multi-Sensor Data Logger

  Sensors:
  - DHT11 (Temperature & Humidity)
  - LDR (Light Level)
  - HC-SR04 Ultrasonic Sensor

  Output every 5 seconds
*/

#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

const int ldrPin = A0;

const int trigPin = 8;
const int echoPin = 9;

void setup() {

  Serial.begin(9600);

  dht.begin();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  int ldrValue = analogRead(ldrPin);

  int lightPercent = map(ldrValue, 0, 1023, 0, 100);

  String lightStatus;

  if (lightPercent >= 70)
    lightStatus = "Bright";
  else if (lightPercent >= 40)
    lightStatus = "Normal";
  else
    lightStatus = "Dark";

  // HC-SR04 Distance Measurement
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  float distance = duration * 0.0343 / 2;

  Serial.println("=== SENSOR LOG ===");

  Serial.print("Time      : ");
  Serial.print(millis());
  Serial.println(" ms");

  Serial.print("Temp      : ");
  Serial.print(temperature);
  Serial.print(" C | Humidity: ");
  Serial.print(humidity);
  Serial.println("%");

  Serial.print("Light     : ");
  Serial.print(lightPercent);
  Serial.print("% (");
  Serial.print(lightStatus);
  Serial.println(")");

  Serial.print("Distance  : ");
  Serial.print(distance);
  Serial.println(" cm");

  Serial.println("==================");
  Serial.println();

  delay(5000);
}
