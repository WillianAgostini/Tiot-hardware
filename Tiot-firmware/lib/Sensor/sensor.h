#ifndef sensor_H // include guard
#define sensor_H

#include "defines.h"
#include <DallasTemperature.h>
#include <OneWire.h>

class Sensor {
private:
  float temperature = DEVICE_DISCONNECTED_C;
  unsigned long lastMsg = 0;
  unsigned const int LoopInterval = 1000;
  void RequestTemperature();
  OneWire oneWire = OneWire(ONE_WIRE_BUS);
  DallasTemperature sensors = DallasTemperature(&oneWire);

public:
  Sensor();
  void InitSensor();
  void Loop();
  float GetTemperature();
};

#endif
