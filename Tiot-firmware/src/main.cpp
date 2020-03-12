#include "debug.h"
#include "mqtt.h"
#include "ota.h"
#include "serial.h"
#include "soneca.h"
#include "telnet.h"
#include "wifi.h"

SerialUsb usb;
WifiClass wifi;
Telnet telnet;
Ota ota;
SerialUsb Soneca::serialUsb = usb;
Telnet Soneca::telnet = telnet;

void setup() {
  usb.InitSerial();
  telnet.InitTelNet();
  wifi.InitWifi();
  ota.InitOta();
  InitMqtt();
}

void loop() {
  ota.LoopOta();
  telnet.TelNetMonitor();
  LoopMqtt();
}