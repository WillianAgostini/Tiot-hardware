#ifndef OTA_H // include guard
#define OTA_H

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

void Init();
void Loop();
void EnableSerial();

#endif