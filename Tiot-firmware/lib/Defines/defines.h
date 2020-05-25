#ifndef defines_H // include guard
#define defines_H

#include <Arduino.h>
#include <EEPROM.h>

#define TiotPub "homer/packet"
#define TiotPubMin "homer/min"
#define TiotPubMax "homer/max"
#define TiotPubIp "homer/ip"
#define TiotPubStatus "homer/status"
#define TiotSub "homer/action"

#define WifiSsid "Btelway_Marines"
#define OtaHostName "homer.local"
#define ClientName "homerClient"
// #define MqttServer "broker.mqtt-dashboard.com"
#define MqttServer "191.52.140.35"
// #define MqttServer "192.168.1.30"
// #define MqttServer "172.20.165.20"

#define PinThermostat 25
#define ONE_WIRE_BUS 13

static volatile bool wifi_connected = false; // global variable

#endif