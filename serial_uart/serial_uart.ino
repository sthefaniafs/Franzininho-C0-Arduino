void setup() {
  // Conecta a UART aos pinos ligados à USB
  Serial.setRx(PA_10_R);
  Serial.setTx(PA_9_R);
  // Inicia a serial
  Serial.begin(115200);
}

void loop() {
  Serial.println("Ola, Franzininho C0!");
  delay(1000);
}