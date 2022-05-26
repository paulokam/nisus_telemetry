#include <Telemetry.h>
#include <Wire.h>

Telemetry::Telemetry(Gps &gps, Gyroscope &gyro, Barometer &baro)
    : _gps{gps}, _gyro{gyro}, _baro{baro}
{
}

bool Telemetry::init()
{
    Wire.begin();
    Serial2.begin(this->baudRate);
    Serial.println("Inicializando sensores...");

    if (_gps.isActive())
    {
        Serial.println("Inicializando GPS...");
        _gps.init();
    }

    if (_baro.isActive())
    {
        Serial.println("Inicializando Barometro...");
        if (_baro.init())
        {
            Serial.println("Barometro iniciado");
        }
    }
    if (_gyro.isActive())
    {
        Serial.println("Inicializando Gyroscópio...");
        if (_gyro.init())
        {
            Serial.println("Gyroscópio iniciado");
        }
    }

    return 1;
}

void Telemetry::getData() const
{
    if (_gps.isActive())
    {
        Serial.print(_gps.getData());
    }

    if (_baro.isActive())
    {
        Serial.print(_baro.getData());
    }

    if (_gyro.isActive())
    {
        Serial.print(_gyro.getData());
    }
}

void Telemetry::sendData() const
{
    String aux = "";

    if (_gps.isActive())
    {
        aux.concat(_gps.getData());
    }
   
    if (_baro.isActive())
    {
        aux.concat(_baro.getData());
    }
    
    if (_gyro.isActive())
    {
        Serial2.print('X'+String(_gyro.pitch(),1)+';');
        Serial2.print('Y'+String(_gyro.roll(),1)+';');
        Serial2.print('W'+String(_gyro.accX(),1)+';');
        Serial2.print('K'+String(_gyro.accY(),1)+';');
        delay(10);
        //aux.concat(_gyro.getData());
    }

    Serial2.print(aux);
}

void Telemetry::smartDelay(int val)
{
    unsigned long start = millis();
    
    do
    {
        this->_gyro.update();
        
        while (Serial1.available())
            _gps.update();

    } while (millis() - start < val);
}
