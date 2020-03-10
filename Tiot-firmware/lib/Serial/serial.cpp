#include "serial.h"

void InitSerial() {
  Serial.begin(115200);
  Serial.println("Iniciando...");
}