#ifndef thermostat_H // include guard
#define thermostat_H

#include "defines.h"
#include "sensor.h"

class Thermostat {
private:
  double minValue;
  double maxValue;
  Sensor *sensor;
  float temperature;
  unsigned long lastMsg = 0;
  unsigned const int LoopInterval = 1000;

  bool goToMin = true;
  bool IsHot();
  bool IsCold();
  bool IsOk();

public:
  Thermostat(Sensor *Sensor);
  void RefreshValues();
  void Loop();
};
#endif
