#include <Wire.h>
#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

// Endereço I2C do SSD1306
#define I2C_ADDRESS 0x3C

// Define pinos
#define SCL_PIN PB6
#define SDA_PIN PC14

  /*
  #if RST_PIN >= 0
    oled.begin(&Adafruit128x64, I2C_ADDRESS, RST_PIN);
  #else // RST_PIN >= 0
    oled.begin(&Adafruit128x64, I2C_ADDRESS);
  #endif // RST_PIN >= 0
  
  oled.setFont(Adafruit5x7);
  oled.clear();
  //oled.set2X(); */

/* 
 * Teste do sensor DHT11 
 *  
 * Daniel Quadros - 31/07/18 
 * https://dqsoft.blogspot.com 
 */  
static const int DHTPIN = PA5;  
static const int timeout = 200;  
  
// Resposta do sensor  
typedef struct  
{  
  byte umidInt;  
  byte umidDec;  
  byte tempInt;  
  byte tempDec;  
  byte checksum;  
} RESPOSTA;  
  
// Iniciação  
void setup() {  
  pinMode (DHTPIN, INPUT);
  
  // Conecta a UART aos pinos ligados à USB
  Serial.setRx(PA_10_R);
  Serial.setTx(PA_9_R);  
  Serial.begin (9600);  
}  
  
// Laço Principal  
void loop() {  
  RESPOSTA resp;  
  delay (5000);   // ler a cada 5 segundos  
  if (leDHT11(&resp)) {  
    Serial.print ("Temperatura ");  
    Serial.print (resp.tempInt);  
    Serial.print (",");  
    Serial.print (resp.tempDec);  
    Serial.print ("C umidade ");  
    Serial.print (resp.umidInt);  
    Serial.print (",");  
    Serial.print (resp.umidDec);  
    Serial.println ("%");  
  } else {  
    Serial.println ("Falha na leitura");  
  }  
}  
  
// Efetua a leitura  
bool leDHT11 (RESPOSTA *pResp) {  
  byte *pDados = (byte *) pResp;  
  byte iByte, iBit;  
  unsigned long to;  
  
  // Solicita leitura  
  pinMode (DHTPIN, OUTPUT);  
  digitalWrite (DHTPIN, LOW);  
  delay (20);    
  digitalWrite (DHTPIN, LOW);  
  
  // Aguarda confirmar  
  pinMode (DHTPIN, INPUT);  
  to = micros() + timeout;  
  while (digitalRead(DHTPIN) == HIGH) {  
    if (micros() > to) {  
      return false;  
    }  
  }  
  while (digitalRead(DHTPIN) == LOW) {  
    if (micros() > to) {  
      return false;  
    }  
  }  
  while (digitalRead(DHTPIN) == HIGH) {  
    if (micros() > to) {  
      return false;  
    }  
  }  
  
  // Le os dados  
  iByte = iBit = 0;  
  while (iByte < 5) {  
    // pulso inicial  
    to = micros() + timeout;  
    while (digitalRead(DHTPIN) == LOW) {  
      if (micros() > to) {  
        return false;  
      }  
    }  
    // valor do bit  
    to = micros() + timeout;  
    while (digitalRead(DHTPIN) == HIGH) {  
      if (micros() > to) {  
        return false;  
      }  
    }  
    pDados[iByte] = pDados[iByte] << 1;  
    if (((micros() + timeout) - to) > 40) {  
      pDados[iByte] |= 1;  
    }  
    // passa para o próximo bit  
    if (++iBit > 7) {  
      iBit = 0;  
      iByte++;  
    }  
  }  
    
  // Confere o checksum  
  return (pDados[0]+pDados[1]+pDados[2]+pDados[3]) == pDados[4];  
}  
