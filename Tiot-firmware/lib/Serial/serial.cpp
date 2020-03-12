#include "serial.h"

void SerialUsb::InitSerial() {
  Serial.begin(115200);
  Print("Iniciando...");
}

void SerialUsb::Print(const char *c) {
  if (Serial.availableForWrite())
    Serial.print(c);
}

// void SerialUsb::Print(const char c) {
//   if (Serial.availableForWrite())
//     Serial.print(c);
// }

void SerialUsb::Println(const char *c) {
  if (Serial.availableForWrite())
    Serial.println(c);
}
