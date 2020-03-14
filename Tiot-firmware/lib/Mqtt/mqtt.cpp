#include "mqtt.h"

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long lastMsg = 0;
char msg[50];

unsigned const int LoopInterval = 5000;
const char *mqtt_server = "broker.mqtt-dashboard.com";

void callback(char *topic, byte *payload, int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");

  // TODO
  if (topic == TiotSub) {
    int value;
    for (int i = 0; i < length; i++) {
      int incoming = (int)payload[i] - '0';
      Serial.print(incoming);
      value = incoming;
    }
    Serial.println("");
  }
}

void InitMqtt() {
  client.setServer(mqtt_server, 1883);
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
      client.publish("/uhuul", "hello world");
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
    snprintf(msg, 50, "hello world #%ld");
    Serial.print("Publish message: ");
    Serial.println(msg);
    client.publish(TiotPub, msg);
  }
}