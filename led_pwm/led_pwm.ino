#define POT A0
#define LED PB7

void setup() {
  // Inicia o pino de controle do LED
  pinMode (LED, OUTPUT);
}

void loop() {
  // Faz uma leitura que varia de 0 a 1023
  int adc = analogRead(POT);
  // Define o duty cycle como um valor que varia de 0 a 255
  analogWrite(LED, adc >> 2);
  // Isso é feito a cada 100 ms
  delay(100);
}