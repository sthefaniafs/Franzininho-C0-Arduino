#include <Wire.h>
#include <BMP180.h>

// Define pinos
#define SCL_PIN PB6
#define SDA_PIN PC14

BMP180 myBMP(BMP180_ULTRAHIGHRES);

void setup() {
  // Conecta a UART aos pinos ligados à USB
  Serial.setRx(PA_10_R);
  Serial.setTx(PA_9_R);
  
  // Inicia a serial
  Serial.begin(115200);

  // Define pinos do I2C
  Wire.setSCL(SCL_PIN);
  Wire.setSDA(SDA_PIN);
  Wire.begin();

  delay(500);

  while (myBMP.begin() != true)
  {
    Serial.println(F("Bosch BMP180/BMP085 is not connected or fail to read calibration coefficients"));
    delay(5000);
  }
  
  Serial.println(F("Bosch BMP180/BMP085 sensor is OK")); //(F()) saves string to flash & keeps dynamic memory free 
}

void loop() {
  Serial.print(F("Temperature: ")); 
  Serial.print(myBMP.getTemperature(), 1);
  //Serial.print(F("Pressure..........: ")); Serial.print(myBMP.getPressure());       Serial.println(F(" +-100Pa"));
  //Serial.print(F("See level pressure: ")); Serial.print(myBMP.getSeaLevelPressure(115)); Serial.println(F(" Pa"));

  //Serial.print(F("Starts over again in 5 sec."));
  delay(5000); 

}
