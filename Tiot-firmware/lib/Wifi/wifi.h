#ifndef wifi_H // include guard
#define wifi_H

#include "defines.h"
#include "soneca.h"
#include <WiFi.h>

class WifiClass {
private:
public:
  WifiClass(/* args */);
  void InitWifi();
};

#endif