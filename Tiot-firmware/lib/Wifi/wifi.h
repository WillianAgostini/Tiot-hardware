#ifndef wifi_H // include guard
#define wifi_H

#include "libs.h"
#include "soneca.h"
#include <ESP8266WiFi.h>

class WifiClass {
private:
  const char *ssid = "Btelway_Marines";

public:
  WifiClass(/* args */);
  void InitWifi();
};

#endif