#include <WiFi.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";
const char* API_KEY = "YOUR_API_KEY"; //enter the api key from the openweathermap site
const char* CITY = "Jammu";
const char* SCRIPT_URL = "YOUR_SCRIPT_URL"; //example: https://script.google.com/macros/s/AKfycb.../exec

#define SOIL_PIN   34
#define LDR_PIN    35
#define BUTTON_PIN 18
#define PUMP_PIN   19

const unsigned long READ_INTERVAL = 30000;   
const unsigned long LOCKOUT       = 300000;  

unsigned long lastRead = 0, lastWatered = 0, lastOverride = 0;
bool rainAPI = false, rainLDR = false, pumping = false;
int soilPct = 0, lightRaw = 0;
String soilState = "";

// ---------- WiFi ----------
void initWiFi() {
  Serial.print("Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) { Serial.print("."); delay(500); }
  Serial.println("\nWiFi Connected");
}

// ---------- Weather API ----------
bool getRainAPI() {
  HTTPClient http;
  String url = "http://api.openweathermap.org/data/2.5/weather?q=" +
               String(CITY) + "&appid=" + String(API_KEY);
  http.begin(url);
  bool rain = false;
  if (http.GET() == 200) {
    DynamicJsonDocument doc(2048);
    deserializeJson(doc, http.getString());
    String w = doc["weather"][0]["main"];
    rain = (w == "Rain" || w == "Drizzle" || w == "Thunderstorm");
  }
  http.end();
  return rain;
}

// ---------- Sensors ----------
void getSoil() {
  int raw = analogRead(SOIL_PIN);
  soilPct = map(raw, 0, 4095, 0, 100);
  soilState = (soilPct < 30) ? "DRY" : (soilPct < 70) ? "OPTIMAL" : "WET";
}

void getLight() {
  lightRaw = analogRead(LDR_PIN);
  rainLDR = (lightRaw < 1500);
}

// ---------- Pump ----------
void activatePump() {
  pumping = true;
  digitalWrite(PUMP_PIN, HIGH);
  lcd.clear();
  lcd.setCursor(0, 0); lcd.print("Pump Running");
  lcd.setCursor(0, 1); lcd.print("Watering...");
  delay(5000);
  digitalWrite(PUMP_PIN, LOW);
  pumping = false;
  lastWatered = millis();
}

// ---------- Display ----------
void showStatus() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("M:"); lcd.print(soilPct); lcd.print("% "); lcd.print(soilState);
  lcd.setCursor(0, 1);
  lcd.print("Last:"); lcd.print(lastWatered / 1000); lcd.print("s");
}

// ---------- Serial log ----------
void logSerial() {
  Serial.println("-----------------------");
  Serial.printf("Moisture : %d%%\n", soilPct);
  Serial.printf("State    : %s\n", soilState.c_str());
  Serial.printf("LDR Rain : %s\n", rainLDR ? "YES" : "NO");
  Serial.printf("API Rain : %s\n", rainAPI ? "YES" : "NO");
  Serial.printf("Last Watered : %lu sec\n", lastWatered / 1000);
}

// ---------- Cloud logging ----------
void sendToSheets() {
  if (WiFi.status() != WL_CONNECTED) return;
  HTTPClient http;
  String url = String(SCRIPT_URL) + "?moisture=" + String(soilPct) +
               "&status=" + soilState + "&rain=" + String(rainAPI);
  http.begin(url);
  http.GET();
  http.end();
}

// ---------- Manual override ----------
void checkOverride() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    if (millis() - lastOverride >= LOCKOUT) {
      lastOverride = millis();
      Serial.println("Manual Override Activated");
      activatePump();
    } else {
      Serial.println("Manual Override Locked");
    }
  }
}

// ---------- Setup ----------
void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  digitalWrite(PUMP_PIN, LOW);
  initWiFi();
  lcd.setCursor(0, 0); lcd.print("Plant Watering");
  lcd.setCursor(0, 1); lcd.print("System Ready");
  delay(2000);
}

// ---------- Loop ----------
void loop() {
  checkOverride();

  if (millis() - lastRead >= READ_INTERVAL) {
    lastRead = millis();

    getSoil();
    getLight();
    rainAPI = getRainAPI();

    showStatus();
    logSerial();
    sendToSheets();

    if (soilState == "DRY") {
      if (!rainLDR && !rainAPI) {
        Serial.println("Conditions OK - Starting Pump");
        activatePump();
      } else {
        Serial.println("Watering Skipped - Rain Detected");
      }
    } else if (soilState == "OPTIMAL") {
      Serial.println("Soil Moisture Optimal");
    } else {
      Serial.println("Soil Already Wet");
    }
    Serial.println();
  }
}
