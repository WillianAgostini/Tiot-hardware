#ifndef mqtt_H // include guard
#define mqtt_H

#include "libs.h"
#include "soneca.h"
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

void InitMqtt();
void LoopMqtt();
#endif
