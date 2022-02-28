#include "TelemetriaNISUS.h"
long timer = 0;
//Barometer baro;
Gyroscope gyro;
//Gps _gps;
void setup() {
  // put your setup code here, to run once:
  Serial2.begin(4800);
  Serial.begin(9600);
//  Wire.begin(21,22); //SDA, SCL mpu6050
//  Wire.begin(12,13); //SDA, SCI bmp280
  
  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  gyro.update();
  if(millis() - timer > 1000)
  {
//    Serial.println("----------------BAROMETER-----------------");
//    Serial.print(F("TEMPERATURE BMP: "));Serial.println(baro.temperature());
//    Serial.print(F("PRESSURE BMP: "));Serial.println(baro.pressure());
//    Serial.print(F("ALTITUDE BMP: "));Serial.println(baro.alt());
//
    Serial.println("----------------GYROSCOPE-----------------");
    Serial.print(("PITCH GYRO: "));Serial.println(gyro.pitch());
    Serial.print(("ROLL GYRO: "));Serial.println(gyro.roll());
    Serial.print(("YAW GYRO: "));Serial.println(gyro.yaw());
    Serial.print(("ACCX GYRO: "));Serial.println(gyro.accX());
    Serial.print(("ACCY GYRO: "));Serial.println(gyro.accY());
    Serial.print(("ACCZ GYRO: "));Serial.println(gyro.accZ());

//    Serial.println("-------------------GPS--------------------");
//    Serial.print(F("SATTELITES GPS: "));Serial.println(_gps.nSatellites());
//    Serial.print(F("ALTITUDE GPS: "));Serial.println(_gps.alt());
//    Serial.print(F("SPEED GPS: "));Serial.println(_gps.speed());
//    Serial.print(F("SPEED GPS: "));Serial.println(_gps.lon());
//    Serial.print(F("SPEED GPS: "));Serial.println(_gps.lat());
    
    
    timer = millis();
  }
}
