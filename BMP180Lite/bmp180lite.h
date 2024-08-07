// BMP180Lite.h
#ifndef BMP180LITE_H
#define BMP180LITE_H

#include <Wire.h>

#define BMP180_GET_ID_REG             0xD0   //device id register
#define BMP180_GET_VERSION_REG        0xD1   //device version register

#define BMP180_SOFT_RESET_REG         0xE0   //soft reset register
#define BMP180_SOFT_RESET_CTRL        0xB6   //soft reset control

#define BMP180_START_MEASURMENT_REG   0xF4   //start measurment  register
#define BMP180_READ_ADC_MSB_REG       0xF6   //read adc msb  register
#define BMP180_READ_ADC_LSB_REG       0xF7   //read adc lsb  register
#define BMP180_READ_ADC_XLSB_REG      0xF8   //read adc xlsb register

/* BMP180_START_MEASURMENT_REG controls */
#define BMP180_GET_TEMPERATURE_CTRL   0x2E   //get temperature control
#define BMP180_GET_PRESSURE_OSS0_CTRL 0x34   //get pressure oversampling 1 time/oss0 control
#define BMP180_GET_PRESSURE_OSS1_CTRL 0x74   //get pressure oversampling 2 time/oss1 control
#define BMP180_GET_PRESSURE_OSS2_CTRL 0xB4   //get pressure oversampling 4 time/oss2 control
#define BMP180_GET_PRESSURE_OSS3_CTRL 0xF4   //get pressure oversampling 8 time/oss3 control

/* misc */
#define BMP180_ADDRESS                0x77   //i2c address
#define BMP180_CHIP_ID                0x55   //id number

#define BMP180_ERROR                  255    //returns 255, if communication error is occurred


class BMP180Lite {
public:
  BMP180Lite();
  bool begin();
  float readTemperature();
  float readPressure();
  float readAltitude(float seaLevelPressure = 1013.25);

private:
  uint8_t read8(uint8_t reg);
  uint16_t read16(uint8_t reg);
  int16_t readS16(uint8_t reg);
  int16_t readRawTemperature();
  int32_t readRawPressure();
};

#endif // BMP180LITE_H
