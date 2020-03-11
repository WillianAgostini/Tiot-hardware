#include "libs.h"

#ifndef telnet_H // include guard
#define telnet_H

class Telnet {
private:
  WiFiClient Client; // Telnet Client Declaration
  bool hasClient = false;
  WiFiServer *TelnetServer;

public:
  Telnet(/* args */);
  void InitTelNet();
  void TelNetMonitor();
};

#endif