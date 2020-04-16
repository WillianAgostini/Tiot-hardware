#ifndef defines_H // include guard
#define defines_H

#include <Arduino.h>
#include <EEPROM.h>

#define TiotPub "caveira"
#define TiotPubMin "caveira/min"
#define TiotPubMax "caveira/max"
#define TiotSub "caveira/action"

#define WifiSsid "Btelway_Marines"
#define OtaHostName "caveira.local"
// #define MqttServer "broker.mqtt-dashboard.com"
#define MqttServer "192.168.1.30"

#define PinThermostat 25
#define ONE_WIRE_BUS 13

#endif