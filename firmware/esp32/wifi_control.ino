// wifi_control.ino - ESP32 telemetry server (Arduino core)
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "MECHADRIVE_AP";
const char* password = "mechadrake";
WebServer server(80);

void handleRoot(){
  server.send(200, "text/plain", "MechaDrake ESP32 telemetry alive\n");
}

void setup(){
  Serial.begin(115200);
  WiFi.softAP(ssid, password);
  server.on("/", handleRoot);
  server.begin();
}

void loop(){
  server.handleClient();
}
