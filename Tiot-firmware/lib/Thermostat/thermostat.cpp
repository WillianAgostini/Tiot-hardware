#include "thermostat.h"

Thermostat::Thermostat(Sensor *Sensor) {
  sensor = Sensor;
  pinMode(PinThermostat, OUTPUT);
  RefreshValues();
}

void Thermostat::RefreshValues() {
  minValue = EEPROM.read(0);
  maxValue = EEPROM.read(1);
  Serial.println("#############");
  Serial.println(IsHot());
  Serial.println(IsCold());
  Serial.println(IsOk());
  Serial.println("/////////////");
}

bool Thermostat::IsHot() { return temperature > maxValue; }

bool Thermostat::IsCold() { return temperature < minValue; }

bool Thermostat::IsOk() {
  return temperature < maxValue && temperature > minValue;
}

void Thermostat::Loop() {
  temperature = sensor->GetTemperature();
  ;
  if (IsHot())
    digitalWrite(PinThermostat, HIGH);

  if (IsCold() || IsOk())
    digitalWrite(PinThermostat, LOW);

  unsigned long now = millis();
  if (now - lastMsg > LoopInterval) {
    lastMsg = now;
    RefreshValues();
  }
}
