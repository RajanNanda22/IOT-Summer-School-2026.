/*
  Q33 - Wi-Fi Temperature Monitor
  ESP8266 / ESP32 Web Server
  Author - Rajan Nanda
  Date - 7-7-2026

  Features:
  - Connects to Wi-Fi
  - Reads DHT11
  - Serves HTML page
  - Auto refresh every 10 seconds
  - LED Toggle Button
  - Displays Device Uptime
*/

#include "secrets.h"

#ifdef ESP32
  #include <WiFi.h>
  #include <WebServer.h>
  WebServer server(80);
#else
  #include <ESP8266WiFi.h>
  #include <ESP8266WebServer.h>
  ESP8266WebServer server(80);
#endif

#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11

#define LED_PIN 2

DHT dht(DHTPIN, DHTTYPE);

bool ledState = false;

void handleRoot();
void handleToggle();

void setup() {

  Serial.begin(115200);

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  dht.begin();

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("Connected!");

  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/toggle", handleToggle);

  server.begin();
}

void loop() {
  server.handleClient();
}

void handleToggle() {

  ledState = !ledState;

  digitalWrite(LED_PIN, ledState);

  server.sendHeader("Location","/");
  server.send(303);
}

void handleRoot() {

  float t = dht.readTemperature();
  float h = dht.readHumidity();

  unsigned long seconds = millis()/1000;

  String html;

  html += "<!DOCTYPE html>";
  html += "<html>";
  html += "<head>";

  html += "<meta http-equiv='refresh' content='10'>";

  html += "<title>ESP Temperature Monitor</title>";

  html += "<style>";

  html += "body{font-family:Arial;text-align:center;background:#f2f2f2;}";

  html += "div{background:white;width:350px;margin:auto;padding:20px;border-radius:10px;}";

  html += "button{padding:12px 25px;font-size:18px;}";

  html += "</style>";

  html += "</head>";

  html += "<body>";

  html += "<div>";

  html += "<h2>Wi-Fi Temperature Monitor</h2>";

  html += "<h3>Temperature : " + String(t) + " &deg;C</h3>";

  html += "<h3>Humidity : " + String(h) + " %</h3>";

  html += "<h3>LED : ";
  html += (ledState ? "ON" : "OFF");
  html += "</h3>";

  html += "<h3>Uptime : ";
  html += String(seconds);
  html += " seconds</h3>";

  html += "<form action='/toggle'>";

  html += "<button>Toggle LED</button>";

  html += "</form>";

  html += "</div>";

  html += "</body>";

  html += "</html>";

  server.send(200,"text/html",html);
}
