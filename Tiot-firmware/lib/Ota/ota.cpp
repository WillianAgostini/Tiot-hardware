#include "ota.hpp"


const char* ssid = "Btelway_Marines";
const char* password = "SENHA DA SUA REDE WIFI";

IPAddress ip(192, 168, 1, 200);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress dns(8, 8, 8, 8);

WiFiClient SerialOTA;     // Telnet Client Declaration 
bool haveClient = false;
WiFiServer TelnetServer(23); 

void Init(){
Serial.begin(115200);
  Serial.println("Iniciando...");

  WiFi.config(ip,gateway,subnet,dns);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Conexao falhou! Reiniciando...");
    delay(5000);
    ESP.restart();
  }
 
  // Porta padrao do ESP8266 para OTA eh 8266 - Voce pode mudar ser quiser, mas deixe indicado!
  ArduinoOTA.setPort(8266);
 
  // O Hostname padrao eh esp8266-[ChipID], mas voce pode mudar com essa funcao
  ArduinoOTA.setHostname("caveira.local");
 
  // Nenhuma senha eh pedida, mas voce pode dar mais seguranca pedindo uma senha pra gravar
  // ArduinoOTA.setPassword((const char *)"123");
 
  ArduinoOTA.onStart([]() {
    Serial.println("Inicio...");
  });

  ArduinoOTA.onEnd([]() {
    Serial.println("nFim!");
  });
  
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    Serial.printf("Progresso: %u%%r", (progress / (total / 100)));
  });
  
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Erro [%u]: ", error);
    if (error == OTA_AUTH_ERROR) Serial.println("Autenticacao Falhou");
    else if (error == OTA_BEGIN_ERROR) Serial.println("Falha no Inicio");
    else if (error == OTA_CONNECT_ERROR) Serial.println("Falha na Conexao");
    else if (error == OTA_RECEIVE_ERROR) Serial.println("Falha na Recepcao");
    else if (error == OTA_END_ERROR) Serial.println("Falha no Fim");
  });
  
  ArduinoOTA.begin();
  Serial.println("Pronto");
  Serial.print("Endereco IP: ");
  Serial.println(WiFi.localIP());

  TelnetServer.begin();
  TelnetServer.setNoDelay(true);
}

void Loop(){
  ArduinoOTA.handle();
}

void EnableSerial(){
    if (!haveClient) {
    // Check for new client connections.
    SerialOTA = TelnetServer.available();        
    if (SerialOTA) {
      haveClient = true;
    }
  } else if (!SerialOTA.connected()) {
    // The current client has been disconnected.
    SerialOTA.printf("Game Over");
    SerialOTA.stop();
    SerialOTA = WiFiClient();
    haveClient = false;
  }

  
  
  // if(haveClient)
  //   SerialOTA.printf("caveira");

}
