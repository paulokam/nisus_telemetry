#ifndef TELEMETRY_H
#define TELEMETRY_H

#include <Gps.h>
#include <Barometer.h>
#include <Gyroscope.h>
#include <Arduino.h>

class Telemetry
{
public:
    Telemetry(Gps &gps, Gyroscope &gyro, Barometer &baro);

    void getData() const;
    void sendData() const;
    bool init();
    void smartDelay(int val);

private:
    Gps &_gps;
    Gyroscope &_gyro;
    Barometer &_baro;

    int baudRate = 9600;
};

#endif