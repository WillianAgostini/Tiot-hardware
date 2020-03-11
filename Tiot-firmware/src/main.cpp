#include "mqtt.h"
#include "ota.h"
#include "serial.h"
#include "telnet.h"
#include "wifi.h"

SerialUsb *usb = new SerialUsb();
WifiClass *wifi = new WifiClass();
Telnet *telnet = new Telnet();
Ota *ota = new Ota();

void setup() {

  usb->InitSerial();
  wifi->InitWifi();
  telnet->InitTelNet();
  ota->InitOta();
  InitMqtt();
}

void loop() {
  ota->LoopOta();
  telnet->TelNetMonitor();
  LoopMqtt();
}