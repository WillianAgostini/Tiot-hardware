#include "sensor.h"

Sensor::Sensor() {}

void Sensor::InitSensor() { sensors.begin(); }

void Sensor::Loop() {
  // RequestTemperature();
  unsigned long now = millis();
  if (now - lastMsg > LoopInterval) {
    lastMsg = now;
    RequestTemperature();
  }
}

void Sensor::RequestTemperature() {
  sensors.requestTemperatures();
  temperature = sensors.getTempCByIndex(0);
  // Serial.print(temperature);
  // Serial.println("ºC");
}

float Sensor::GetTemperature() { return temperature; }
