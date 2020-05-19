#include "defines.h"
#include "mqtt.h"
#include "ota.h"
#include "sensor.h"
#include "serial.h"
#include "soneca.h"
#include "telnet.h"
#include "thermostat.h"
#include "wifi.h"

#include <WiFi.h>

SerialUsb usb;
// Telnet telnet;
Ota ota;
// SerialUsb Soneca::serialUsb = usb;
// Telnet Soneca::telnet = telnet;
Sensor sensor;
Thermostat thermostat(&sensor);

void setup() {
  // telnet.InitTelNet();
  EEPROM.begin(4); // Inicia a EEPROM com tamanho de 4 Bytes (minimo).

  usb.InitSerial();
  InitWifi();
  ota.InitOta();
  sensor.InitSensor();
  InitMqtt(&sensor);
}

void loop() {
  // telnet.TelNetMonitor();

  ota.LoopOta();
  LoopMqtt();
  sensor.Loop();
  thermostat.Loop();
}
