#ifndef serial_H // include guard
#define serial_H

#include "defines.h"

class SerialUsb {
public:
  void InitSerial();
  void Print(const char *c);
  // void Print(const char c);
  void Println(const char *c);
};
extern SerialUsb serialUsb;

#endif
