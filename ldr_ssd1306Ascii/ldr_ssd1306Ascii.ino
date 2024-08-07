#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// Endereço I2C do SSD1306
#define I2C_ADDRESS 0x3C

// Define pinos
#define LDR A0
#define LED PB7
#define SCL_PIN PB6
#define SDA_PIN PC14

// Limite de luminosidade para acender o LED
#define LIGHT_THRESHOLD 400

// Define reset do display
#define RST_PIN -1

SSD1306AsciiWire oled;

uint8_t colValueStart;  // Coluna de início para o valor do LDR
uint8_t rowValue;       // Linha para o valor do LDR

//------------------------------------------------------------------------------
void setup() {
  Wire.setSCL(SCL_PIN);
  Wire.setSDA(SDA_PIN);
  Wire.begin();

  // Inicializa LED como saída
  pinMode(LED, OUTPUT);

#if RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
#else // RST_PIN >= 0
  oled.begin(&Adafruit128x64, I2C_ADDRESS);
#endif // RST_PIN >= 0

  oled.setFont(Adafruit5x7);
  oled.clear();

  oled.set2X();
  // Exibe o rótulo fixo uma vez
  oled.println("LDR value:");

  // Calcular a posição inicial para o valor do LDR
  colValueStart = 0; // Valor começará da primeira coluna
  rowValue = oled.fontRows();  // Uma linha abaixo do "LDR value"
}


// Limpa a área do valor do LDR
void clearLdrValue() {
  oled.clear(colValueStart, oled.displayWidth() - 1, rowValue, rowValue + oled.fontRows() - 1);
}

void loop() {
  // Lê o valor analógico do pino LDR
  int ldrValue = analogRead(LDR);

  clearLdrValue();

  // Exibir o novo valor do LDR
  oled.setCursor(colValueStart, rowValue);
  oled.print(ldrValue);

  // Acender o LED se a luminosidade estiver abaixo do limite
  if (ldrValue < LIGHT_THRESHOLD) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

  // Pequeno atraso para não sobrecarregar a comunicação serial e o display
  delay(500);
}
