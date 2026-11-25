// PR 11: ESP32 to ESP32 Wi-Fi (RECEIVER)
// Upload first and note Receiver IP from Serial Monitor (115200 baud)

#include <WiFi.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* pass = "YOUR_WIFI_PASSWORD";
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("\nReceiver IP: ");
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String data = client.readStringUntil('\n');
    data.trim();
    if (data.length() > 0) {
      Serial.println("Received -> " + data);
    }
    client.stop();
  }
}
