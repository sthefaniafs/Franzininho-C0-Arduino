//mapeamento de pinos
#define ledG A5   // Pino do LED verde
#define ledY A6   // Pino do LED amarelo
#define ledR A7   // Pino do LED vermelho

void setup() {
   // Configura o pino do LED como saída
  pinMode(ledG, OUTPUT);
  pinMode(ledY, OUTPUT); 
  pinMode(ledR, OUTPUT); 
}

void loop() {
  digitalWrite(ledR, HIGH); 
  delay(3000);
  digitalWrite(ledR, LOW); 
  digitalWrite(ledG, HIGH); 
  delay(3000);
  digitalWrite(ledG, LOW); 
  digitalWrite(ledY, HIGH); 
  delay(2000);
  digitalWrite(ledY, LOW); 
}