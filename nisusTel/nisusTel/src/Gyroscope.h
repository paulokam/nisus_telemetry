#ifndef GYROSCOPE_HPP
#define GYROSCOPE_HPP

#include <MPU6050_light.h>

class Gyroscope
{
  friend class Telemetry;

private:
  MPU6050 *_gyroscope;
  bool active;

public:
  Gyroscope(bool activeStatus = true);
  ~Gyroscope();

  bool init();

  virtual bool isActive() const;   // Return if sensor is active
  virtual bool activate();   // Activate sensor
  virtual bool deactivate(); // Deactivate sensor

  float pitch(); // returns pitch in degrees (rotation X)
  float roll();  // returns roll in degrees (rotation Y)
  float yaw();   // returns yaw in degrees (rotation Z)

  float accX(); // returns acceleration in the X axis
  float accY(); // returns acceleration in the Y axis
  float accZ(); // returns acceleration in the Z axis
  void update();

  String getData();
};

#endif