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
      initAuth();
      WiFi.begin(WifiSsid);
    }
  }
}

void InitWifi() {
  delay(10);

  // WiFi.config(ip, gateway, subnet, dns);

  WiFi.disconnect(true); // disconnect form wifi to set new wifi connection
  WiFi.mode(WIFI_STA);   // init wifi mode
  initAuth();

  WiFi.begin(WifiSsid);

  delay(1);
  WiFi.setHostname(OtaHostName);
  WiFi.onEvent(WiFiEvent);
}
void initAuth() {
  esp_wifi_sta_wpa2_ent_set_identity(
      (uint8_t *)EAP_ANONYMOUS_IDENTITY,
      strlen(EAP_ANONYMOUS_IDENTITY)); // provide identity
  esp_wifi_sta_wpa2_ent_set_username((uint8_t *)EAP_IDENTITY,
                                     strlen(EAP_IDENTITY)); // provide username
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)EAP_PASSWORD,
                                     strlen(EAP_PASSWORD)); // provide password
  esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT();
  esp_wifi_sta_wpa2_ent_enable(&config);
}