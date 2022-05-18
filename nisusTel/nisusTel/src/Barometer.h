#ifndef BAROMETER_HPP
#define BAROMETER_HPP

#include <Adafruit_BMP280.h>

class Barometer {
    friend class Telemetry;

  private:
    Adafruit_BMP280* _barometer;
    float _pressure0 = 1013.25;
    bool active;

    const uint8_t chipAdress = 118;

    


  public:
    Barometer(bool activeStatus = true);
    ~Barometer();

    bool isActive() const;    //Return if sensor is active
    
    void activate();    //Activate sensor
    void deactivate();    //Deactivate sensor

    bool init();


    float temperature() const; //return temperature
    float pressure() const; //return pressure
    float alt() const; //return altitude
    
    void setPressure0(float value);

    String getData() ;//float* _pressure = nullptr, float* _temperature = nullptr, float* _alt = nullptr);
};


#endif