/*
  Bluetooth Sensor Dashboard (ESP32 BLE)
  Author - Rajan Nanda 
  Date - 7-7-2026

  Broadcast DHT11 data every 3 seconds using BLE.

  BLE Service:
    Environmental Sensor Service

  Characteristics:
    Temperature
    Humidity
    Timestamp

  Compatible Apps:
    - nRF Connect
    - LightBlue
*/

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// Custom UUIDs
#define SERVICE_UUID        "12345678-1234-1234-1234-123456789000"
#define TEMP_UUID           "12345678-1234-1234-1234-123456789001"
#define HUM_UUID            "12345678-1234-1234-1234-123456789002"
#define TIME_UUID           "12345678-1234-1234-1234-123456789003"

BLECharacteristic *tempCharacteristic;
BLECharacteristic *humCharacteristic;
BLECharacteristic *timeCharacteristic;

unsigned long lastUpdate = 0;

void setup() {

  Serial.begin(115200);

  dht.begin();

  BLEDevice::init("ESP32 BLE Sensor");

  BLEServer *server = BLEDevice::createServer();

  BLEService *service = server->createService(SERVICE_UUID);

  tempCharacteristic = service->createCharacteristic(
      TEMP_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  humCharacteristic = service->createCharacteristic(
      HUM_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  timeCharacteristic = service->createCharacteristic(
      TIME_UUID,
      BLECharacteristic::PROPERTY_READ |
      BLECharacteristic::PROPERTY_NOTIFY
  );

  // Add Client Characteristic Configuration Descriptor (CCCD)
  tempCharacteristic->addDescriptor(new BLE2902());
  humCharacteristic->addDescriptor(new BLE2902());
  timeCharacteristic->addDescriptor(new BLE2902());

  // User Description Descriptors
  tempCharacteristic->addDescriptor(new BLEDescriptor(BLEUUID((uint16_t)0x2901)));
  humCharacteristic->addDescriptor(new BLEDescriptor(BLEUUID((uint16_t)0x2901)));
  timeCharacteristic->addDescriptor(new BLEDescriptor(BLEUUID((uint16_t)0x2901)));

  service->start();

  BLEAdvertising *advertising = BLEDevice::getAdvertising();
  advertising->addServiceUUID(SERVICE_UUID);
  advertising->start();

  Serial.println("BLE Sensor Started");
}

void loop() {

  if (millis() - lastUpdate >= 3000) {

    lastUpdate = millis();

    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    if (isnan(temperature) || isnan(humidity)) {
      Serial.println("Failed to read DHT11");
      return;
    }

    String tempValue = String(temperature, 1) + " C";
    String humValue = String(humidity, 1) + " %";
    String timeValue = String(millis() / 1000) + " sec";

    tempCharacteristic->setValue(tempValue.c_str());
    humCharacteristic->setValue(humValue.c_str());
    timeCharacteristic->setValue(timeValue.c_str());

    tempCharacteristic->notify();
    humCharacteristic->notify();
    timeCharacteristic->notify();

    Serial.println("------------------------");
    Serial.println("Temperature : " + tempValue);
    Serial.println("Humidity    : " + humValue);
    Serial.println("Timestamp   : " + timeValue);
  }
}
