#include "wifi.h"

IPAddress ip(192, 168, 1, 200);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(8, 8, 8, 8);

WifiClass::WifiClass(/* args */) {}

void WifiClass::InitWifi() {
  delay(10);

  WiFi.config(ip, gateway, subnet, dns);
  WiFi.begin(WifiSsid);
  delay(1);
  WiFi.setHostname(OtaHostName);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    // Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  randomSeed(micros());
}