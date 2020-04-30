#ifndef wifi_H // include guard
#define wifi_H

#include "defines.h"
#include "soneca.h"
#include <WiFi.h>

void InitWifi();
void WiFiEvent(WiFiEvent_t event);
void ShowIp();

#endif