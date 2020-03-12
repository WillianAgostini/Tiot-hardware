#ifndef soneca_H // include guard
#define soneca_H

#include "libs.h"
#include "serial.h"
#include "telnet.h"

class Soneca {
private:
  /* data */
public:
  static Telnet telnet;
  static SerialUsb serialUsb;

  // static void Set(Telnet &telnet, SerialUsb &serialUsb);
  static void Print(char *c); 
  // static void Print(char c);
  static void Print(String c);
  static void Println(char *c);
  static void Println(String c);
};
extern Soneca soneca;

#endif
