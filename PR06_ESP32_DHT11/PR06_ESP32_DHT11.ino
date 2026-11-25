// PR 6: DHT11 Temperature & Humidity (ESP32)
// Wiring: VCC -> 3.3V, GND -> GND, DATA -> GPIO 4

#include <DHT.h>

#define DHTPIN 4
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("DHT11 Read Failed!");
  } else {
    Serial.print("Temp: ");
    Serial.print(t);
    Serial.print(" C | Humidity: ");
    Serial.print(h);
    Serial.println(" %");
  }
  delay(2000);
}
