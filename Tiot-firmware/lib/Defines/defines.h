#ifndef defines_H // include guard
#define defines_H

#include <Arduino.h>
#include <EEPROM.h>

#define TiotPub "caveira"
#define TiotPubMin "caveira/min"
#define TiotPubMax "caveira/max"
#define TiotSub "caveira/action"

#define WifiSsid "MiPhone"
#define OtaHostName "caveira.local"
#define ClientName "caveiraClient"
// #define MqttServer "broker.mqtt-dashboard.com"
#define MqttServer "191.52.140.35"
// #define MqttServer "172.20.165.20"

#define PinThermostat 25
#define ONE_WIRE_BUS 13

static volatile bool wifi_connected = false; // global variable

#endif