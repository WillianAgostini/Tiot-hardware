#include "thermostat.h"

Thermostat::Thermostat(Sensor *Sensor) {
  sensor = Sensor;
  pinMode(PinThermostat, OUTPUT);
  RefreshValues();
}

void Thermostat::RefreshValues() {
  int signalMin = EEPROM.read(0);
  minValue = EEPROM.read(1) / 10;
  if (signalMin)
    minValue *= -1;

  int signalMax = EEPROM.read(2);
  maxValue = EEPROM.read(3) / 10;
  if (signalMax)
    maxValue *= -1;
}

bool Thermostat::IsHot() {
  goToMin = true;
  return temperature > maxValue;
}

bool Thermostat::IsCold() {
  goToMin = false;
  return temperature < minValue;
}

bool Thermostat::IsOk() {
  return temperature < maxValue && temperature > minValue;
}

void Thermostat::Loop() {
  temperature = sensor->GetTemperature();

  if (IsHot())
    digitalWrite(PinThermostat, HIGH);

  if (IsCold() && !goToMin)
    digitalWrite(PinThermostat, LOW);

  unsigned long now = millis();
  if (now - lastMsg > LoopInterval) {
    lastMsg = now;
    RefreshValues();
  }
}
