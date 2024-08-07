#include <Wire.h>
#include <U8g2lib.h>

// Inicializar o display usando a biblioteca U8g2
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE, /* clock=*/ PB6, /* data=*/ PB7);

// Definir o pino analógico onde o LDR está conectado
#define LDR A0
#define LED PB7
#define SCL_PIN PB6
#define SDA_PIN PC14

// Limite de luminosidade para acender o LED
#define LIGHT_THRESHOLD 300

void setup() {
   // Inicializando o Wire com os pinos definidos
  Wire.setSCL(SCL_PIN);
  Wire.setSDA(SDA_PIN);
  // Inicializar o LED como saída
  pinMode(LED, OUTPUT);

  // Inicializar o display
  u8g2.begin();
}

void loop() {
  // Ler o valor analógico do pino LDR
  int ldrValue = analogRead(LDR);

  // Atualizar o display com o valor do LDR
  u8g2.clearBuffer();                  // Limpar o buffer
  u8g2.setFont(u8g2_font_ncenB08_tr);  // Selecionar a fonte
  u8g2.drawStr(0, 10, "LDR Value:");   // Desenhar o texto
  u8g2.setCursor(0, 30);
  u8g2.print(ldrValue);                // Desenhar o valor do LDR
  u8g2.sendBuffer();                   // Transferir o buffer para o display

  // Acender o LED se a luminosidade estiver abaixo do limite
  if (ldrValue < LIGHT_THRESHOLD) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  // Pequeno atraso para não sobrecarregar a comunicação serial e o display
  delay(500);
}
