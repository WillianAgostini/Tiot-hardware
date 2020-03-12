#include "soneca.h"

// void Soneca::Set(Telnet &telnet, SerialUsb &serialUsb) {
//   Soneca::telnet = telnet;
//   Soneca::serialUsb = serialUsb;
// }

void Soneca::Print(char *c) {
  telnet.Print(c);
  serialUsb.Print(c);
}

void Soneca::Print(String c) {
  telnet.Print(c.c_str());
  serialUsb.Print(c.c_str());
}