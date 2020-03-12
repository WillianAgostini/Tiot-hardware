#include "soneca.h"

// void Soneca::Set(Telnet &telnet, SerialUsb &serialUsb) {
//   Soneca::telnet = telnet;
//   Soneca::serialUsb = serialUsb;
// }

void Soneca::Print(char *c) {
  telnet.Print(c);
  serialUsb.Print(c);
}

// void Soneca::Print(char c) {
//   telnet.Print(c);
//   serialUsb.Print(c);
// }

void Soneca::Print(String c) {
  char cstr[c.length() + 1];
  strcpy(cstr, c.c_str());
  telnet.Print(cstr);
  serialUsb.Print(cstr);
}
