#include <WiFi.h>
#include <PubSubClient.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";
const char* mqtt_server = "broker.hivemq.com";

WiFiClient espClient;
PubSubClient mqtt(espClient);

#define DHTPIN     4
#define DHTTYPE    DHT22
#define LDR_PIN    34
#define HEATER_PIN 25
#define FAN_PIN    26
#define LIGHT_PIN  27

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

float tempMin = 18, tempMax = 22, tempHyst = 1;
float humMax = 70, humHyst = 5;

int ldrBuf[10] = {0};
int ldrIdx = 0;
int lcdMode = 0;

unsigned long lastLCD = 0, lastPublish = 0;

// ---------- WiFi ----------
void initWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting WiFi");
  while (WiFi.status() != WL_CONNECTED) { delay(300); Serial.print("."); }
  Serial.println("\nWiFi Connected");
}

// ---------- MQTT ----------
void reconnectMQTT() {
  while (!mqtt.connected()) {
    Serial.print("Connecting MQTT...");
    if (mqtt.connect("ESP32Greenhouse")) {
      Serial.println("Connected");
    } else {
      Serial.print("Failed rc="); Serial.print(mqtt.state());
      delay(1000);
    }
  }
}

// ---------- LDR running average ----------
int getLightAvg() {
  ldrBuf[ldrIdx] = analogRead(LDR_PIN);
  ldrIdx = (ldrIdx + 1) % 10;
  long sum = 0;
  for (int i = 0; i < 10; i++) sum += ldrBuf[i];
  return sum / 10;
}

// ---------- Bang-bang control w/ hysteresis ----------
void applyControl(float t, float h, int l) {
  if (t < tempMin - tempHyst) {
    digitalWrite(HEATER_PIN, HIGH);
    digitalWrite(FAN_PIN, LOW);
  } else if (t > tempMax + tempHyst) {
    digitalWrite(FAN_PIN, HIGH);
    digitalWrite(HEATER_PIN, LOW);
  }
  if (h > humMax + humHyst) digitalWrite(FAN_PIN, HIGH);
  digitalWrite(LIGHT_PIN, (l < 1500) ? HIGH : LOW);
}

// ---------- Serial + MQTT publish ----------
void publishData(float t, float h, int l) {
  Serial.println("------ GREENHOUSE DATA ------");
  Serial.printf("Temperature: %.1f C\n", t);
  Serial.printf("Humidity   : %.1f %%\n", h);
  Serial.printf("Light Avg  : %d\n", l);
  Serial.printf("Heater:%d Fan:%d Light:%d\n",
                digitalRead(HEATER_PIN), digitalRead(FAN_PIN), digitalRead(LIGHT_PIN));
  Serial.println("-----------------------------\n");

  mqtt.publish("greenhouse/temp", String(t).c_str());
  mqtt.publish("greenhouse/humidity", String(h).c_str());
  mqtt.publish("greenhouse/light", String(l).c_str());
  mqtt.publish("greenhouse/heater", String(digitalRead(HEATER_PIN)).c_str());
  mqtt.publish("greenhouse/fan", String(digitalRead(FAN_PIN)).c_str());
  mqtt.publish("greenhouse/lightStatus", String(digitalRead(LIGHT_PIN)).c_str());
}

// ---------- LCD cycling ----------
void updateLCD(float t, float h, int l) {
  if (millis() - lastLCD > 3000) {
    lcdMode = (lcdMode + 1) % 3;
    lastLCD = millis();
    lcd.clear();
  }

  if (lcdMode == 0) {
    lcd.setCursor(0, 0); lcd.print("Temp:"); lcd.print(t);
    lcd.setCursor(0, 1); lcd.print("Hum:");  lcd.print(h);
  } else if (lcdMode == 1) {
    lcd.setCursor(0, 0); lcd.print("Light:");
    lcd.setCursor(0, 1); lcd.print(l);
  } else {
    lcd.setCursor(0, 0);
    lcd.print("H:"); lcd.print(digitalRead(HEATER_PIN));
    lcd.print(" F:"); lcd.print(digitalRead(FAN_PIN));
    lcd.setCursor(0, 1);
    lcd.print("L:"); lcd.print(digitalRead(LIGHT_PIN));
  }
}

// ---------- Setup ----------
void setup() {
  Serial.begin(115200);

  pinMode(HEATER_PIN, OUTPUT);
  pinMode(FAN_PIN, OUTPUT);
  pinMode(LIGHT_PIN, OUTPUT);

  dht.begin();
  lcd.init();
  lcd.backlight();

  initWiFi();
  mqtt.setServer(mqtt_server, 1883);
}

// ---------- Loop ----------
void loop() {
  if (!mqtt.connected()) reconnectMQTT();
  mqtt.loop();

  float temp = dht.readTemperature();
  float hum  = dht.readHumidity();
  if (isnan(temp) || isnan(hum)) return;

  int light = getLightAvg();

  applyControl(temp, hum, light);
  updateLCD(temp, hum, light);

  if (millis() - lastPublish > 3000) {
    lastPublish = millis();
    publishData(temp, hum, light);
  }

  delay(200);
}
