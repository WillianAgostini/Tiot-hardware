#include "thermostat.h"

Thermostat::Thermostat(Sensor *Sensor) {
  EEPROM.begin(4); // Inicia a EEPROM com tamanho de 4 Bytes (minimo).
  sensor = Sensor;
  pinMode(PinThermostat, OUTPUT);
  RefreshValues();
}

void Thermostat::RefreshValues() {
  minValue = EEPROM.read(0);
  maxValue = EEPROM.read(1);
}

bool Thermostat::IsHot() { return temperature > maxValue; }

bool Thermostat::IsCold() { return temperature < minValue; }

bool Thermostat::IsOk() {
  return temperature < maxValue && temperature > minValue;
}

void Thermostat::Loop() {
  temperature = sensor->GetTemperature();

  if (IsHot())
    digitalWrite(PinThermostat, HIGH);

  if (IsCold() || IsOk())
    digitalWrite(PinThermostat, LOW);
}
