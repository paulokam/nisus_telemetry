#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <Gps.h>
#include <Barometer.h>
#include <Gyroscope.h>
#include <Arduino.h>

class Telemetry
{
public:
    Telemetry(Gps *gps, Gyroscope *gyro, Barometer *baro);

    void sendData();

private:
    Gps *_gps;
    Gyroscope *_gyro;
    Barometer *_baro;
};

#endif