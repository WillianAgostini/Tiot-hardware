#include "libs.h"
#include "mqtt.h"
#include "ota.h"
#include "serial.h"
#include "soneca.h"
#include "telnet.h"
#include "wifi.h"

#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

SerialUsb usb;
WifiClass wifi;
Telnet telnet;
Ota ota;
SerialUsb Soneca::serialUsb = usb;
Telnet Soneca::telnet = telnet;

void InitTime() {
  timeClient.begin();
  timeClient.update();
}

void setup() {
  usb.InitSerial();
  telnet.InitTelNet();
  wifi.InitWifi();
  ota.InitOta();
  InitMqtt();
  InitTime();
}

void loop() {
  ota.LoopOta();
  telnet.TelNetMonitor();
  LoopMqtt();
}
