#ifndef OTA_H // include guard
#define OTA_H

#include "defines.h"
#include <ArduinoOTA.h>
#include <WiFiUdp.h>

class Ota {
private:
  /* data */
public:
  Ota(/* args */);
  void InitOta();
  void LoopOta();
  //   void PrintSerial(char *text);
};

#endif