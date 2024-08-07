#include <Wire.h>
#include <U8g2lib.h>

// Definindo os pinos SCL e SDA
#define SCL_PIN PB6
#define SDA_PIN PC14

// Inicializando a instância U8G2 para o SSD1306 com I2C
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

void setup() {
  // Inicializando o Wire com os pinos definidos
  Wire.setSCL(SCL_PIN);
  Wire.setSDA(SDA_PIN);
  Wire.begin();

  // Inicializando o display
  u8g2.begin();
  u8g2.clearBuffer();          // Limpa o buffer

  // Configurações do display
  u8g2.setFont(u8g2_font_t0_14b_tf); // Seleciona uma fonte
  u8g2.drawStr(0, 10, "Hello,"); // Desenha a string no buffer
  u8g2.drawStr(0, 30, "Franzininho C0!");

  u8g2.sendBuffer();          // Transfere o buffer para o display
}

void loop() {
  // O loop vazio, já que estamos apenas exibindo uma mensagem inicial
}
