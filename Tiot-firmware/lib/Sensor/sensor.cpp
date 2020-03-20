#include "sensor.h"

Sensor::Sensor(int GPIO) {
  // GPIO where the DS18B20 is connected to
  const int oneWireBus = GPIO;

  // Setup a oneWire instance to communicate with any OneWire devices
  OneWire oneWire(oneWireBus);

  // Pass our oneWire reference to Dallas Temperature sensor
  sensors = DallasTemperature(&oneWire);
}

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
  Serial.print(temperature);
  Serial.println("ºC");
}

float Sensor::GetTemperature() { return temperature; }
