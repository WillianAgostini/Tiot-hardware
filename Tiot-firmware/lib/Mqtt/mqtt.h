#ifndef mqtt_H // include guard
#define mqtt_H

#include "defines.h"
#include "sensor.h"
#include "soneca.h"

#include <EEPROM.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

void InitMqtt(Sensor *newSensor, int Gpio);
void LoopMqtt();
void reconnect();
void callback(char *topic, byte *payload, int length);
void Publish();
void ActuatorActionMax(char *topic, byte *payload, int length);
void ActuatorActionMin(char *topic, byte *payload, int length);
int GetValue(char *topic, byte *payload, int length);
void PublishInterval();

#endif
