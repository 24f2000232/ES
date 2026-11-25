// PR 7: LDR Automatic Lighting (ESP32)
// Wiring: LDR VCC -> 3.3V, GND -> GND, DO -> GPIO 4

void setup() {
  pinMode(4, INPUT);    // LDR DO -> GPIO 4
  pinMode(2, OUTPUT);   // Built-in LED -> GPIO 2
}

void loop() {
  if (digitalRead(4) == LOW)   // Dark -> LED ON (swap to HIGH if inverted)
    digitalWrite(2, HIGH);
  else
    digitalWrite(2, LOW);
  delay(200);
}
