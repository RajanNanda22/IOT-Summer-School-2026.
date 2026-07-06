/*
 MQTT Sensor Publisher (ESP32)

  Publishes:
    iitjammu/summer26/Rajan/temperature
    iitjammu/summer26/Rajan/humidity

  Subscribes:
    iitjammu/summer26/rajan/led_control

  JSON Format:
  {"value":28.5,"unit":"C","ts":1234567890}
*/

#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include "secrets.h"

#define DHTPIN 4
#define DHTTYPE DHT11
#define LED_PIN 2

DHT dht(DHTPIN, DHTTYPE);

WiFiClient espClient;
PubSubClient client(espClient);

// Change "yourname" to your own name
const char* tempTopic = "iitjammu/summer26/yourname/temperature";
const char* humTopic  = "iitjammu/summer26/yourname/humidity";
const char* ledTopic  = "iitjammu/summer26/yourname/led_control";

unsigned long lastPublish = 0;

void callback(char* topic, byte* payload, unsigned int length) {

  String message;

  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.print("Received: ");
  Serial.println(message);

  if (message == "ON") {
    digitalWrite(LED_PIN, HIGH);
  }

  else if (message == "OFF") {
    digitalWrite(LED_PIN, LOW);
  }
}

void connectMQTT() {

  while (!client.connected()) {

    Serial.print("Connecting to MQTT...");

    if (client.connect("ESP32Client")) {

      Serial.println("Connected");

      client.subscribe(ledTopic);

    } else {

      Serial.print("Failed, rc=");
      Serial.println(client.state());

      delay(3000);
    }
  }
}

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);

  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected");

  client.setServer(MQTT_SERVER, MQTT_PORT);
  client.setCallback(callback);
}

void loop() {

  if (!client.connected()) {
    connectMQTT();
  }

  client.loop();

  if (millis() - lastPublish >= 5000) {

    lastPublish = millis();

    float t = dht.readTemperature();
    float h = dht.readHumidity();

    if (isnan(t) || isnan(h))
      return;

    unsigned long ts = millis();

    String tempJSON =
      "{\"value\":" + String(t,1) +
      ",\"unit\":\"C\",\"ts\":" + String(ts) + "}";

    String humJSON =
      "{\"value\":" + String(h,1) +
      ",\"unit\":\"%\",\"ts\":" + String(ts) + "}";

    client.publish(tempTopic, tempJSON.c_str());
    client.publish(humTopic, humJSON.c_str());

    Serial.println(tempJSON);
    Serial.println(humJSON);
  }
}
