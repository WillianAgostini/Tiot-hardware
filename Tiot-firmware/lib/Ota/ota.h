#ifndef OTA_H // include guard
#define OTA_H

#include "libs.h"
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