#include "telnet.h"

Telnet::Telnet(/* args */) { TelnetServer = new WiFiServer(23); }

void Telnet::InitTelNet() {

  TelnetServer->begin();
  TelnetServer->setNoDelay(true);
}

void Telnet::TelNetMonitor() {

  if (!hasClient) {
    Client = TelnetServer->available();
    if (Client)
      hasClient = true;
  }

  if (!Client.connected()) {
    Client.stop();
    Client = WiFiClient();
    hasClient = false;
  }
}

void Telnet::Print(const char *c) {
  if (Client)
    Client.println(c);
}