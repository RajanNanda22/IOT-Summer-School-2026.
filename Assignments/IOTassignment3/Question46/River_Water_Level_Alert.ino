#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

String apiKey = "APIKEY";  //enter API KEY
const char* server = "http://api.thingspeak.com/update";

#define TRIG_PIN    5
#define ECHO_PIN    18
#define BUZZER      4
#define LED_GREEN   12
#define LED_YELLOW  13
#define LED_RED     14

float readings[5];
int idx = 0;

// ---------- WiFi ----------
void initWiFi() {
  Serial.print("Connecting WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { delay(500); Serial.print("."); }
  Serial.println("\nWiFi Connected!");
}

// ---------- Ultrasonic read ----------
float readUltrasonic() {
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}

// ---------- Rolling average ----------
float rollingAvg(float val) {
  readings[idx] = val;
  idx = (idx + 1) % 5;
  float sum = 0;
  for (int i = 0; i < 5; i++) sum += readings[i];
  return sum / 5;
}

// ---------- Cloud push ----------
void pushToCloud(float distance, int levelValue) {
  if (WiFi.status() != WL_CONNECTED) return;
  HTTPClient http;
  String url = String(server) + "?api_key=" + apiKey +
               "&field1=" + String(distance) +
               "&field2=" + String(levelValue);
  Serial.println("Sending to TS: " + url);
  http.begin(url);
  int code = http.GET();
  Serial.print("HTTP Response: "); Serial.println(code);
  http.end();
}

// ---------- Setup ----------
void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);

  for (int i = 0; i < 5; i++) readings[i] = 30;

  initWiFi();

  tone(BUZZER, 1000); delay(300); noTone(BUZZER);
}

// ---------- Loop ----------
void loop() {
  float raw = readUltrasonic();
  float avg = rollingAvg(raw);

  Serial.print("Raw: "); Serial.print(raw);
  Serial.print(" cm | Avg: "); Serial.println(avg);

  String level;
  int levelValue;

  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_RED, LOW);
  noTone(BUZZER);

  if (raw < 15) {
    level = "CRITICAL"; levelValue = 2;
    digitalWrite(LED_RED, HIGH);
    tone(BUZZER, 3000);
  }
  else if (raw <= 30) {
    level = "WARNING"; levelValue = 1;
    digitalWrite(LED_YELLOW, HIGH);
    tone(BUZZER, 2000);
    delay(200);
    noTone(BUZZER);
  }
  else {
    level = "NORMAL"; levelValue = 0;
    digitalWrite(LED_GREEN, HIGH);
  }

  Serial.println("Level: " + level);

  pushToCloud(avg, levelValue);

  delay(15000); // ThingSpeak free-tier rate limit
}
