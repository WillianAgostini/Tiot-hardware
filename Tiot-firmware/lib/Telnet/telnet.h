#ifndef telnet_H // include guard
#define telnet_H

#include "libs.h"
#include <ESP8266WiFi.h>

class Telnet {
private:
  WiFiClient Client; // Telnet Client Declaration
  bool hasClient = false;
  WiFiServer *TelnetServer;

public:
  Telnet(/* args */);
  void InitTelNet();
  void TelNetMonitor();
  void Print(const char *c);
  // void Print(const char c);
  void Println(const char *c);
};

#endif