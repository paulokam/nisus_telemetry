#include <Arduino.h>
#include <Telemetry.h>

Gps *const gps_false = new Gps(false);
Barometer *const baro_true = new Barometer(true);
Gyroscope *const gyro_false = new Gyroscope(false);
Telemetry tel(gps_false, gyro_false, baro_true);

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, false);

    Serial.begin(115200);
    delay(4000);

    digitalWrite(LED_BUILTIN, true);


    Serial.print("Gps_false:");
    Serial.println(gps_false->isActive());
    Serial.print("baro_true:");
    Serial.println(baro_true->isActive());
    Serial.print("gyro_true:");
    Serial.println(gyro_false->isActive());
}

void loop()
{
    tel.sendData();
    delay(1000);
}