const int potPin = A4; // Pino analógico onde o potenciômetro está conectado
const int pwmPin = A0;  // Pino PWM onde o sinal PWM será gerado

void setup() {
  Serial.setRx(PA_10_R);
  Serial.setTx(PA_9_R);
  Serial.begin(9600); // Inicializa a comunicação serial para depuração
  pinMode(potPin, INPUT); // Define o pino potenciômetro como saída
  pinMode(pwmPin, OUTPUT); // Define o pino PWM como saída
}

void loop() {
  int potValue = analogRead(potPin); // Lê o valor do potenciômetro (0-1023)
  int pwmValue = map(potValue, 0, 1023, 0, 255); // Mapeia o valor do potenciômetro para o intervalo PWM (0-255)

  analogWrite(pwmPin, pwmValue); // Ajusta o duty cycle do sinal PWM

  // Simula a onda PWM no Serial Plotter
  for (int i = 0; i < 255; i++) {
    if (i < pwmValue) {
      Serial.println(255); // Alto nível do PWM
    } else {
      Serial.println(0); // Baixo nível do PWM
    }
  }

  delay(100); // Pequeno atraso para suavizar as leituras
  
}
