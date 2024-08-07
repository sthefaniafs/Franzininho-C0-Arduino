#include <Wire.h>
#include "bmp180lite.h"

BMP180Lite bmp180;

void setup() {
    Serial.begin(9600);
    if (bmp180.begin()) {
        Serial.println("BMP180 inicializado com sucesso.");
    } else {
        Serial.println("Erro na inicialização do BMP180.");
    }
}

void loop() {
    float temperature = bmp180.readTemperature();
    float pressure = bmp180.readPressure();
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.print(" C, Pressão: ");
    Serial.print(pressure);
    Serial.println(" hPa");
    delay(2000);
}
