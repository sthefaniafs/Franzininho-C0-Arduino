#define LED1 PB6 // consulte https://docs.franzininho.com.br/docs/franzininho-c0/franzininho-c0-board/ para acessar o pinout da placa
#define LED2 PB7

// biblioteca para utilizar timer da Franzininho C0
HardwareTimer *MyTim1; 

void setup() {
  // inicia os LEDs como 0
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);


  // inicia a interrupção de timer para o LED1
  MyTim1 = new HardwareTimer(TIM1); // associa com o Timer 1 da placa
  MyTim1->setOverflow(250000, MICROSEC_FORMAT); // o timer conta de 0 até 250 ms
  MyTim1->attachInterrupt(blinkLED); // quando o temporizador chegar a 250 ms a interrupção ocorre e a função blinkLED é chamada
  MyTim1->resume(); //inicia contagem do Timer

}

// Loop principal
void loop() {
  digitalWrite(LED2, HIGH);
  delay(1000); // acende o LED2 espera 1000 ms
  digitalWrite(LED2, LOW);
  delay(1000); // apaga o LED2 espera 1000 ms
}

// Rotina chamada periodicamente, pisca o LED
void blinkLED(void) {
  static bool ledAceso = false;

  ledAceso = !ledAceso; 	// inverte estado do LED
  digitalWrite(LED1, ledAceso? HIGH : LOW);  // se ledAceso for verdadeiro, o valor retornado será HIGH; caso contrário, será LOW
}