#ifndef mqtt_H // include guard
#define mqtt_H

#include "defines.h"
#include "sensor.h"
#include "soneca.h"

#include <ArduinoJson.h>
#include <EEPROM.h>
#include <PubSubClient.h>
#include <WiFi.h>

void InitMqtt(Sensor *newSensor);
void LoopMqtt();
void reconnect();
void callback(char *topic, byte *payload, int length);
void Publish();
void ActuatorAction(char *topic, byte *payload, int length);
void ActuatorActionMin(char *topic, byte *payload, int length);
String GetValue(char *topic, byte *payload, int length);
void PublishInterval();

#endif
