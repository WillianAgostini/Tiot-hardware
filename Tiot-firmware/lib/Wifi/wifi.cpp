#include "wifi.h"

// IPAddress ip(192, 168, 1, 200);
// IPAddress gateway(192, 168, 1, 1);
// IPAddress subnet(255, 255, 255, 0);
// IPAddress dns(8, 8, 8, 8);

bool lastStatus = false;

void ShowIp() {
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void WiFiEvent(WiFiEvent_t event) {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Conectado");
    lastStatus = true;
    wifi_connected = true;
    ShowIp();
  } else {
    Serial.println("Desconectado");
    wifi_connected = false;

    if (lastStatus == true) {
      lastStatus = false;
      WiFi.begin(WifiSsid);
    }
  }
}

void InitWifi() {
  delay(10);

  // WiFi.config(ip, gateway, subnet, dns);
  WiFi.begin(WifiSsid);
  delay(1);
  WiFi.setHostname(OtaHostName);
  WiFi.onEvent(WiFiEvent);
}