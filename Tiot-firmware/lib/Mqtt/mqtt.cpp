#include "mqtt.h"

WiFiClient espClient;
PubSubClient client(espClient);
Sensor *sensorTemp;
int Gpio = 0;

unsigned long lastMsg = 0;
char msg[50];

unsigned const int LoopInterval = 5000;

void callback(char *topic, byte *payload, int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  if (strcmp(topic, TiotSubMax) == 0)
    ActuatorActionMax(topic, payload, length);

  if (strcmp(topic, TiotSubMin) == 0)
    ActuatorActionMin(topic, payload, length);
}

int GetValue(char *topic, byte *payload, int length) {
  int value = 0;
  for (int i = 0; i < length; i++) {
    int incoming = (int)payload[i] - '0';
    value = incoming;
  }
  return value;
}

void ActuatorActionMax(char *topic, byte *payload, int length) {
  int value = GetValue(topic, payload, length);

  digitalWrite(Gpio, value);
  EEPROM.write(1, value);
  EEPROM.commit();
  Serial.println(
      EEPROM.read(1)); // Mostra no Monitor oque há antes de efetuar a gravação
  PublishInterval();
}

void ActuatorActionMin(char *topic, byte *payload, int length) {
  int value = GetValue(topic, payload, length);

  digitalWrite(Gpio, value);
  EEPROM.write(0, value);
  EEPROM.commit();
  Serial.println(
      EEPROM.read(0)); // Mostra no Monitor oque há antes de efetuar a gravação
  PublishInterval();
}

void PublishInterval() {
  int min = EEPROM.read(0);
  int max = EEPROM.read(1);

  char a[3];
  a[0] = (char)min;
  a[1] = ',';
  a[2] = (char)max;
  String text = min + "," + max;
  client.publish(TiotPubInterval, a);
}
void InitMqtt(Sensor *newSensor, int gpio) {
  EEPROM.begin(4); // Inicia a EEPROM com tamanho de 4 Bytes (minimo).

  sensorTemp = newSensor;
  client.setServer(MqttServer, 1883);
  client.setCallback(callback);
  pinMode(gpio, OUTPUT);
  Gpio = gpio;
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
      client.subscribe(TiotSubMax);
      client.subscribe(TiotSubMin);
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