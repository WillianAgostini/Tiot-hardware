#include "libs.h"

#ifndef serial_H // include guard
#define serial_H

class SerialUsb {
public:
  void InitSerial();
};
extern SerialUsb serialUsb;

#endif
