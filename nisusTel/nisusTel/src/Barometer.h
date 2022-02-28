#ifndef BAROMETER_HPP
#define BAROMETER_HPP

#include <Adafruit_BMP280.h>
#include <Wire.h>

class Barometer {
    friend class Telemetry;

  private:
    Adafruit_BMP280* _barometer;
    float _pressure0 = 1013.25;
    bool active;

    const uint8_t chipAdress = 0x76;


  public:
    Barometer(bool activeStatus = true);
    ~Barometer();

    bool isActive();    //Return if sensor is active
    void activate();    //Activate sensor
    void deactivate();    //Deactivate sensor


    float temperature(); //return temperature
    float pressure(); //return pressure
    float alt(); //return altitude
    void setPressure0(float value);

    String getData();//float* _pressure = nullptr, float* _temperature = nullptr, float* _alt = nullptr);
};


#endif