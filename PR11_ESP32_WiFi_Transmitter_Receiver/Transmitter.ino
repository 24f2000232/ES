// PR 11: ESP32 to ESP32 Wi-Fi (TRANSMITTER)
// Wiring: DHT11 DATA -> GPIO 4, Soil Moisture AO -> GPIO 34

#include <WiFi.h>
#include <DHT.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";
const char* rxIP = "192.168.43.100";   // Receiver IP from Serial Monitor

DHT dht(4, DHT11);

void setup() {
  Serial.begin(115200);
  dht.begin();
  WiFi.begin(ssid, pass);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nTransmitter Ready!");
}

void loop() {
  float temp = dht.readTemperature();
  int soil = analogRead(34);

  if (isnan(temp)) {
    Serial.println("DHT11 Error!");
    delay(2000);
    return;
  }

  String msg = "Temp: " + String(temp, 1) + " C | Soil: " + String(soil);
  Serial.println(msg);

  WiFiClient client;
  if (client.connect(rxIP, 80)) {
    client.println(msg);
    Serial.println("Sent to Receiver!");
    client.stop();
  } else {
    Serial.println("Receiver not found!");
  }
  delay(2000);
}
