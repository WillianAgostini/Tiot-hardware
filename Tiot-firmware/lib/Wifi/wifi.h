#include "libs.h"

#ifndef wifi_H // include guard
#define wifi_H

class WifiClass {
private:
  const char *ssid = "Btelway_Marines";

public:
  WifiClass(/* args */);
  void InitWifi();
};

#endif