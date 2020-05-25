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

  const char *q = doc["min"].as<char *>();
  const char *w = doc["max"].as<char *>();
  double min = strtod(q, NULL);
  double max = strtod(w, NULL);

  // Serial.println(min);
  // Serial.println(max);

  EEPROM.write(0, min < 0 ? 1 : 0);
  EEPROM.write(1, min < 0 ? min * -10 : min * +10);

  EEPROM.write(2, max < 0 ? 1 : 0);
  EEPROM.write(3, max < 0 ? max * -10 : max * 10);
  EEPROM.commit();

  // Serial.println("-----------");
  // Serial.println((double)EEPROM.read(1));
  // Serial.println((double)EEPROM.read(3));
  // Serial.println("___________");

  // PublishInterval();
}

void PublishMin() {
  bool signal = EEPROM.read(0);
  double min = EEPROM.read(1);
  if (signal)
    min *= -1;

  snprintf(minChar, 50, "%.1f", min / 10);
  client.publish(TiotPubMin, minChar);
  Serial.println(minChar);
}

void PublishMax() {
  int signal = EEPROM.read(2);
  float max = EEPROM.read(3);
  if (signal)
    max *= -1;

  snprintf(maxChar, 50, "%.1f", max / 10);
  client.publish(TiotPubMax, maxChar);
  Serial.println(maxChar);
}

void PublishStatus() {
  bool status = digitalRead(PinThermostat);
  client.publish(TiotPubStatus, status ? "1" : "0");
  Serial.println(status);
}

void Publish() {
  bool status = digitalRead(PinThermostat);

  float temp = sensorTemp->GetTemperature();
  snprintf(msg, 50, "%.1f/%d", temp, status);
  Serial.print("Publish message: ");
  Serial.println(msg);
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
    client.publish(TiotPubIp, ip.toString().c_str());
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
      PublishStatus();
    }
  }
}
