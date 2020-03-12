#include "libs.h"

#ifndef serial_H // include guard
#define serial_H

class SerialUsb {
public:
  void InitSerial();
  void Print(const char *c);
};
extern SerialUsb serialUsb;

#endif
