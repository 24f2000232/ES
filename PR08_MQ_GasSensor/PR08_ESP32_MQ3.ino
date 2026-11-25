// PR 8: MQ-Series Gas Sensor (ESP32)
// Wiring: VCC -> 5V (VIN), GND -> GND, AO -> GPIO 34

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);   // Built-in LED (Alert)
}

void loop() {
  int gas = analogRead(34);   // 0 to 4095

  Serial.print("MQ3 Value: ");
  Serial.println(gas);

  if (gas > 2000)
    digitalWrite(2, HIGH);    // Alert ON
  else
    digitalWrite(2, LOW);     // Alert OFF

  delay(500);
}
