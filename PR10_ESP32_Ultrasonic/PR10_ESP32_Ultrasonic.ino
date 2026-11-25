// PR 10: Ultrasonic Sensor HC-SR04 (ESP32)
// Wiring: VCC -> 5V, GND -> GND, TRIG -> GPIO 5, ECHO -> GPIO 18

void setup() {
  Serial.begin(115200);
  pinMode(5, OUTPUT);   // TRIG -> GPIO 5
  pinMode(18, INPUT);   // ECHO -> GPIO 18
}

void loop() {
  digitalWrite(5, HIGH);
  delayMicroseconds(10);
  digitalWrite(5, LOW);

  float dist = pulseIn(18, HIGH) * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(dist);
  Serial.println(" cm");
  delay(500);
}
