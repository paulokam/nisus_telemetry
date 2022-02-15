//Biblioteca de telemetria para a equipe de competição NISUS implementada para microcontrolador ESP32
//Created by Paulo H. A. Kammradt, July 11, 2021

#ifndef TELEMETRIANISUS_H
#define TELEMETRIANISUS_H

#include <Arduino.h>
#include <Wire.h>
#include <TinyGPSPlus.h>
#include <Adafruit_BMP280.h>
#include <MPU6050_light.h>

//#------------------------------------------------------------------------------#
//Classe Sensor
//#------------------------------------------------------------------------------#

class Sensor {
  protected:
    bool active;

  public:
    Sensor(bool activeStatus = true);

    bool isActive();    //Return if sensor is active
    void activate();    //Activate sensor
    void deactivate();    //Deactivate sensor

};

//#------------------------------------------------------------------------------#
//Classe Gps
//#------------------------------------------------------------------------------#

class Gps : public Sensor {
    friend class Telemetry;

  private:
    TinyGPSPlus* _gps;

  public:
    Gps(bool activeStatus = true);
    ~Gps();

    int nSatellites(); //return number of available satelites
    float alt(); //Return altitude
    float speed(); //Return speed
    double gpsHDOP(); //Return HDOP (Precision)
    double lon(); //Return Longitude degree
    double lat(); //Return Latitude degree

    //return all data inside given pointers
    void getData(double* _lat = nullptr, double* _lon = nullptr, float* _alt = nullptr, float* _speed = nullptr, int* _nSatellites = nullptr, double* _gpsHdop = nullptr);

};

//#------------------------------------------------------------------------------#
//Classe Barometro
//#------------------------------------------------------------------------------#

class Barometer : public Sensor {
    friend class Telemetry;

  private:
    Adafruit_BMP280* _barometer;
    float _pressure0 = 1013.25;

  public:
    Barometer(bool activeStatus = true);
    ~Barometer();

    float temperature(); //return temperature
    float pressure(); //return pressure
    float alt(); //return altitude
    void setPressure0(float value);

    //return all data inside given pointers
    void getData(float* _pressure = nullptr, float* _temperature = nullptr, float* _alt = nullptr);
};

//#------------------------------------------------------------------------------#
//Classe Giroscopio
//#------------------------------------------------------------------------------#

class Gyroscope : public Sensor {
    friend class Telemetry;

  private:
    MPU6050* _gyroscope;
  public:
    Gyroscope(bool activeStatus = true);
    ~Gyroscope();

    float pitch(); //returns pitch in degrees (rotation X)
    float roll(); //returns roll in degrees (rotation Y)
    float yaw(); //returns yaw in degrees (rotation Z)

    float accX(); //returns acceleration in the X axis
    float accY(); //returns acceleration in the Y axis
    float accZ(); //returns acceleration in the Z axis
    void update();

    //return all data inside given pointers
    void getData(float* _pitch = nullptr, float* _roll = nullptr, float* _yaw = nullptr, float* _accX = nullptr, float* _accY = nullptr, float* _accZ = nullptr);
};

class Telemetry {
  private:
    Gyroscope* _gyro;
    Gps* _gps;
    Barometer* _baro;
  public:
    Telemetry();
    ~Telemetry();
    
    Gyroscope* gyro(); //returns Gyroscope object
    Gps* gps(); //returns Gps object
    Barometer* baro(); //returns Barometer object
};

#endif