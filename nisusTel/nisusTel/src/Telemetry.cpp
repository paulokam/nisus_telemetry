#include <Telemetry.h>

Telemetry::Telemetry(Gps *gps, Gyroscope *gyro, Barometer *baro)
    : _gps{gps}, _gyro{gyro}, _baro{baro}
{
}

// Only Gps for now
void Telemetry::sendData()
{
    if (_gps->isActive())
    {
        Serial.print(_gps->getData());
    }

    if (_baro->isActive())
    {
        Serial.print(_baro->getData());
    }
}
