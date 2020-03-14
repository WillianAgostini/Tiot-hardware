#include "libs.h"
#include "mqtt.h"
#include "ota.h"
#include "sensor.h"
#include "serial.h"
#include "soneca.h"
#include "telnet.h"
#include "wifi.h"

#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

#define SensorDs18b20 4

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

SerialUsb usb;
WifiClass wifi;
Telnet telnet;
Ota ota;
SerialUsb Soneca::serialUsb = usb;
Telnet Soneca::telnet = telnet;
Sensor sensor(SensorDs18b20);

void InitTime() {
  timeClient.begin();
  timeClient.update();
}

void setup() {
  usb.InitSerial();
  telnet.InitTelNet();
  wifi.InitWifi();
  ota.InitOta();
  sensor.InitSensor();
  InitMqtt(&sensor);
  InitTime();
}

void loop() {
  ota.LoopOta();
  telnet.TelNetMonitor();
  LoopMqtt();
  sensor.Loop();
}
