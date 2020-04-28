#include "mqtt.h"

WiFiClient espClient;
PubSubClient client(espClient);
Sensor *sensorTemp;
unsigned long lastMsg = 0;
char msg[50];
char maxChar[50];
char minChar[50];
long lastReconnectAttempt = 0;
unsigned const int LoopInterval = 5000 / 2;

void callback(char *topic, byte *payload, int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  if (strcmp(topic, TiotSub) == 0)
    ActuatorAction(topic, payload, length);
}

void ActuatorAction(char *topic, byte *payload, int length) {

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, payload, length);
  if (error) {
    Serial.print(F("deserializeJson() failed: "));
    Serial.println(error.c_str());
    return;
  }

  float min = doc["min"];
  float max = doc["max"];

  Serial.println(min);
  Serial.println(min);

  EEPROM.write(0, min);
  EEPROM.write(1, max);
  EEPROM.commit();

  Serial.println("-----------");
  Serial.println((float)EEPROM.read(0));
  Serial.println((float)EEPROM.read(1));
  Serial.println("___________");

  // PublishInterval();
}

void PublishMin() {
  double min = EEPROM.read(0);
  snprintf(minChar, 50, "%f", min);
  client.publish(TiotPubMin, minChar);
}

void PublishMax() {
  double max = EEPROM.read(1);
  snprintf(maxChar, 50, "%f", max);
  client.publish(TiotPubMax, maxChar);
}

void Publish() {
  float temp = sensorTemp->GetTemperature();
  snprintf(msg, 50, "%f", temp);
  // Serial.print("Publish message: ");
  // Serial.println(msg);
  client.publish(TiotPub, msg);
}

void InitMqtt(Sensor *newSensor) {
  sensorTemp = newSensor;

  client.setServer(MqttServer, 1883);
  client.setCallback(callback);
  lastReconnectAttempt = 0;
}

boolean reconnect() {
  if (client.connect(ClientName)) {
    // Once connected, publish an announcement...
    IPAddress ip = WiFi.localIP();
    client.publish(TiotPub, ip.toString().c_str());
    client.subscribe(TiotSub);
    Serial.println("connected");
  }
  return client.connected();
}

void LoopMqtt() {

  if (!client.connected()) {
    long now = millis();
    if (now - lastReconnectAttempt > 5000) {
      lastReconnectAttempt = now;
      Serial.println("Attempt to reconnect");
      if (reconnect()) {
        lastReconnectAttempt = 0;
      }
    }
  } else {
    // Client connected
    client.loop();
    unsigned long now = millis();
    if (now - lastMsg > LoopInterval) {
      lastMsg = now;
      Publish();
      PublishMin();
      PublishMax();
    }
  }
}
