#define LED1 PB6
#define LED2 PB7

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
}

void loop() { 
  
  digitalWrite(LED1, HIGH);
  delay(250); // acende o LED1 espera 250 ms
  digitalWrite(LED1, LOW); 
  delay(250); // apaga o LED1 espera 250 ms
  digitalWrite(LED2, HIGH);
  delay(1000); // acende o LED2 espera 1000 ms
  digitalWrite(LED2, LOW);
  delay(1000); // apaga o LED2 espera 1000 ms
}

