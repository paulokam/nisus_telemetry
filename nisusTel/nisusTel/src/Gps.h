#ifndef GPS_H
#define GPS_H

#include <TinyGPSPlus.h>

class Gps {
    friend class Telemetry;

  private:
    TinyGPSPlus* _gps;
    bool active;

  public:
    Gps(bool activeStatus = true); 
    
    ~Gps();

    int nSatellites(); //return number of available satelites
    float alt(); //Return altitude
    float speed(); //Return speed
    double gpsHDOP(); //Return HDOP (Precision)
    double lon(); //Return Longitude degree
    double lat(); //Return Latitude degree

    bool isActive();    //Return if sensor is active
    void activate();    //Activate sensor
    void deactivate();    //Deactivate sensor

    //return all data inside given pointers
    String getData();

};


#endif