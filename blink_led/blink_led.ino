#define LED PB6 // consulte https://docs.franzininho.com.br/docs/franzininho-c0/franzininho-c0-board/ para acessar o pinout da placa

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);   // acende LED
  delay(1000);              // espera 1 segundo
  digitalWrite(LED, LOW);    // apaga LED
  delay(1000);              // espera 1 segundo
}

