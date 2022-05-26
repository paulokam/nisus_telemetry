#ifndef GPS_H
#define GPS_H

#include <TinyGPSPlus.h>
#include <HardwareSerial.h>

class Gps
{
  friend class Telemetry;

private:
  
  TinyGPSPlus *_gps;
  bool active;

  static const int RXPin = 26, TXPin = 27;
  static const uint32_t baudRate = 4800;

public:
  Gps(bool activeStatus = true);

  ~Gps();

  bool init();

  int nSatellites() const; // return number of available satelites
  float alt() const;       // Return altitude
  float speed() const;     // Return speed
  double gpsHDOP() const;  // Return HDOP (Precision)
  double lon() const;      // Return Longitude degree
  double lat() const;      // Return Latitude degree

  bool isActive() const; // Return if sensor is active

  void activate();   // Activate sensor
  void deactivate(); // Deactivate sensor

  void update();

  // return all data inside given pointers
  String getData() const;
};

#endif