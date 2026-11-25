// PR 12: DHT11 + ESP32 -> ThingSpeak MQTT
// Wiring: DHT11 DATA -> GPIO 4

#include <WiFi.h>
#include <PubSubClient.h>
#include "DHT.h"

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

const char* mqtt_server = "mqtt3.thingspeak.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "channels/YOUR_CHANNEL_ID/publish";
char* mqtt_clientID = "YOUR_CLIENT_ID";
char* mqtt_username = "YOUR_USERNAME";
char* mqtt_password = "YOUR_PASSWORD";

#define DHTPIN 4
#define DHTTYPE DHT11

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHTPIN, DHTTYPE);

void setupWiFi() {
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");
}

void reconnectMQTT() {
  while (!client.connected()) {
    Serial.print("Connecting to MQTT...");
    if (client.connect(mqtt_clientID, mqtt_username, mqtt_password)) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      delay(2000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  dht.begin();
  setupWiFi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnectMQTT();
  }
  client.loop();

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("DHT read failed");
    delay(2000);
    return;
  }

  String payload = "field1=";
  payload += humidity;
  payload += "&field2=";
  payload += temperature;
  payload += "&status=MQTTPUBLISH";

  if (client.connected()) {
    Serial.print("Sending payload: ");
    Serial.println(payload);
    if (client.publish(mqtt_topic, (char*) payload.c_str())) {
      Serial.println("Publish ok");
    } else {
      Serial.println("Publish failed");
    }
    client.disconnect();
    delay(20000);
  }
}
