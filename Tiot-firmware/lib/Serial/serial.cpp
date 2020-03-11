#include "serial.h"

void SerialUsb::InitSerial() {
  Serial.begin(115200);
  Serial.println("Iniciando...");
}