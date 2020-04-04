#ifndef sensor_H // include guard
#define sensor_H

#include <DallasTemperature.h>
#include <OneWire.h>

class Sensor {
private:
  float temperature = -127.00f;
  unsigned long lastMsg = 0;
  unsigned const int LoopInterval = 5000;
  DallasTemperature sensors;

  void RequestTemperature();

public:
  Sensor(int GPIO);
  void InitSensor();
  void Loop();
  float GetTemperature();
};

#endif
