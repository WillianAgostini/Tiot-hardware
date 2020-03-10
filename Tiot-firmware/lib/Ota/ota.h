#include "libs.h"

#ifndef OTA_H // include guard
#define OTA_H

void InitOta();
void Loop();
void TelNetMonitor();
void PrintSerial(char *text);

#endif