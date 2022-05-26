#include <Arduino.h>
#include <Telemetry.h>

Gps gps(true);
Barometer baro(false);
Gyroscope gyro(true);
Telemetry tel(gps, gyro, baro);

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, false);

    Serial.begin(115200);
    delay(4000);

    digitalWrite(LED_BUILTIN, true);

    tel.init();
    delay(1000);
}

void loop()
{
    tel.getData();
    tel.sendData();
    tel.smartDelay(1000);
}
