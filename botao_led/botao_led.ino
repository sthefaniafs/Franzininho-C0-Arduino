#define LED PB6
#define BOTAO 8

void setup() {
  // Configura os pinos
  pinMode(LED, OUTPUT);
  pinMode(BOTAO, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(BOTAO) == LOW) {
    // apertou o botão = acende o LED
    digitalWrite(LED, HIGH);
  } else {
    // soltou o botão = apaga o LED
    digitalWrite(LED, LOW);
  }
}