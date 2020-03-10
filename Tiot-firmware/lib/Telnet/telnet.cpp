#include "telnet.h"

WiFiClient Client; // Telnet Client Declaration
bool hasClient = false;
WiFiServer TelnetServer(23);

void InitTelNet() {
  TelnetServer.begin();
  TelnetServer.setNoDelay(true);
}

void TelNetMonitor() {

  if (!hasClient) {
    Client = TelnetServer.available();
    if (Client)
      hasClient = true;
  }

  if (!Client.connected()) {
    Client.stop();
    Client = WiFiClient();
    hasClient = false;
  }
}