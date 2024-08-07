#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// Endereço I2C do SSD1306
#define I2C_ADDRESS 0x3C

// Define pinos
#define SCL_PIN PB6
#define SDA_PIN PC14
#define digitSensor PA4
#define buzzer PA0

// Define reset do display
#define RST_PIN -1

SSD1306AsciiWire oled;

void setup() {
  // Configura pinos i2c
  Wire.setSCL(SCL_PIN);
  Wire.setSDA(SDA_PIN);
  Wire.begin();

  // Configura pinos uart
  Serial.setRx(PA_10_R);
  Serial.setTx(PA_9_R);
  Serial.begin(115200);

  // Configura entradas e saídas
  pinMode(digitSensor, INPUT); 
  pinMode(buzzer, OUTPUT);

  // Inicia display
  #if RST_PIN >= 0
    oled.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
  #else // RST_PIN >= 0
    oled.begin(&Adafruit128x64, I2C_ADDRESS);
  #endif // RST_PIN >= 0

  oled.setFont(Adafruit5x7);
  oled.clear();
}

void loop() {
  static bool previousState = false; // Variável para armazenar o estado anterior do sensor

  // Leitura do estado atual do sensor
  bool currentState = digitalRead(digitSensor) == 1;

  // Verifica se o estado do sensor mudou
  if (currentState != previousState) {
    previousState = currentState;

    // Limpa e atualiza o display
    oled.clear();
    oled.set2X();

    if (currentState) {
      oled.println("Sem chuva");
      digitalWrite(buzzer, 0);
    } else {
      oled.println("Chovendo");
      digitalWrite(buzzer, 1);
    }
  }

  delay(1000);
}
