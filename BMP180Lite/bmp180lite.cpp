// BMP180Lite.cpp
#include "bmp180lite.h"

BMP180Lite::BMP180Lite() {
    // Construtor
}

bool BMP180Lite::begin() {
    Wire.begin();
    return (read8(BMP180_REG_ID) == BMP180_CHIP_ID);
}

float BMP180Lite::readTemperature() {
    int32_t rawTemp = readRawTemperature();
    // Calcular a temperatura com base no valor rawTemp
    return (rawTemp / 10.0); // Simplificação para exemplo
}

float BMP180Lite::readPressure() {
    int32_t rawPressure = readRawPressure();
    // Calcular a pressão com base no valor rawPressure
    return (rawPressure / 100.0); // Simplificação para exemplo
}

float BMP180Lite::readAltitude(float seaLevelPressure) {
    float pressure = readPressure();
    return 44330.0 * (1.0 - pow(pressure / seaLevelPressure, 0.1903));
}

uint8_t BMP180Lite::read8(uint8_t reg) {
    Wire.beginTransmission(BMP180_ADDRESS);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(BMP180_ADDRESS, (uint8_t)1);
    return Wire.read();
}

uint16_t BMP180Lite::read16(uint8_t reg) {
    Wire.beginTransmission(BMP180_ADDRESS);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(BMP180_ADDRESS, (uint8_t)2);
    return (Wire.read() << 8) | Wire.read();
}

int16_t BMP180Lite::readS16(uint8_t reg) {
    return (int16_t)read16(reg);
}

int32_t BMP180Lite::readRawTemperature() {
   
  /* send temperature measurement command */
  if (write8(BMP180_START_MEASURMENT_REG, BMP180_GET_TEMPERATURE_CTRL) != true) return BMP180_ERROR; //error handler, collision on i2c bus

  /* set measurement delay */
  delay(5);

  /* read result */
  return read16(BMP180_READ_ADC_MSB_REG);       
}

int32_t BMP180Lite::readRawPressure() {
    // Função para ler a pressão bruta
   
  uint8_t  regControl  = 0;
  uint32_t rawPressure = 0;

  /* convert resolution to register control */
  switch (_resolution)
  {
    case BMP180_ULTRALOWPOWER:                    //oss0
      regControl = BMP180_GET_PRESSURE_OSS0_CTRL;
      break;

    case BMP180_STANDARD:                         //oss1
      regControl = BMP180_GET_PRESSURE_OSS1_CTRL;
      break;

    case BMP180_HIGHRES:                          //oss2
      regControl = BMP180_GET_PRESSURE_OSS2_CTRL;
      break;

    case BMP180_ULTRAHIGHRES:                     //oss3
      regControl = BMP180_GET_PRESSURE_OSS3_CTRL;
      break;
}
