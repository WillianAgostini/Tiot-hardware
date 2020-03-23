#include "mqtt.h"

WiFiClient espClient;
PubSubClient client(espClient);
Sensor *sensorTemp;
unsigned long lastMsg = 0;
char msg[50];

unsigned const int LoopInterval = 5000;

void callback(char *topic, byte *payload, int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  if (strcmp(topic, TiotSub) == 0)
    ActuatorAction(topic, payload, length);
}

String GetValue(char *topic, byte *payload, int length) {
  char text[length];
  for (int i = 0; i < length; i++) {
    text[i] = (char)payload[i];
  }
  return String(text);
}

int GetDelimiterIndex(String text) { return text.lastIndexOf('-'); }

int GetMin(String text, int delimiterIndex) {
  return text.substring(0, delimiterIndex).toInt();
}

int GetMax(String text, int delimiterIndex) {
  return text.substring(delimiterIndex + 1, text.length()).toInt();
}

void ActuatorAction(char *topic, byte *payload, int length) {
  String text = GetValue(topic, payload, length);
  int separator = GetDelimiterIndex(text);

  if (separator == 0)
    return;

  int min = GetMin(text, separator);
  int max = GetMax(text, separator);

  EEPROM.write(0, min);
  EEPROM.write(1, max);
  EEPROM.commit();

  Serial.println("-----------");
  Serial.println(EEPROM.read(0));
  Serial.println(EEPROM.read(1));
  Serial.println("___________");

  // PublishInterval();
}

void PublishInterval() {
  int min = EEPROM.read(0);
  int max = EEPROM.read(1);

  char a[2];
  a[0] = min;
  a[1] = max;
  String text = min + "," + max;

  client.publish(TiotPubInterval, a);
}
void InitMqtt(Sensor *newSensor) {
  
  sensorTemp = newSensor;
  client.setServer(MqttServer, 1883);
  client.setCallback(callback);
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish(TiotPub, "hello world");
      // ... and resubscribe
      client.subscribe(TiotSub);
    } else {
      Serial.print("failed, rc=");
      Serial.print((char *)client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void LoopMqtt() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > LoopInterval) {
    lastMsg = now;
    Publish();
  }
}

void Publish() {
  float temp = sensorTemp->GetTemperature();
  snprintf(msg, 50, "%f", temp);
  Serial.print("Publish message: ");
  Serial.println(msg);
  client.publish(TiotPub, msg);
}