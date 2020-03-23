#ifndef thermostat_H // include guard
#define thermostat_H

#include "defines.h"
#include "sensor.h"
#include <EEPROM.h>

class Thermostat {
private:
  float minValue;
  float maxValue;
  Sensor *sensor;
  float temperature;

  bool IsHot();
  bool IsCold();
  bool IsOk();

public:
  Thermostat(Sensor *Sensor);
  void RefreshValues();
  void Loop();
};
#endif
