// PR 9: BMP280 Pressure Sensor (ESP32)
// Wiring: VCC -> 3.3V, GND -> GND, SDA -> GPIO 21, SCL -> GPIO 22
// 6-pin module: CSB -> 3.3V (I2C mode), SDO -> GND (0x76)

#include <Wire.h>
#include <Adafruit_BMP280.h>

Adafruit_BMP280 bmp;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22);

  if (!bmp.begin(0x76)) {
    Serial.println("BMP280 not found!");
    while (1);
  }
  Serial.println("BMP280 Ready");
}

void loop() {
  Serial.print("Pressure: ");
  Serial.print(bmp.readPressure() / 100.0);
  Serial.println(" hPa");
  delay(1000);
}
