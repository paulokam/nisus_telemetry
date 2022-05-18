#include <Barometer.h>
#include <Wire.h>
#include <SPI.h>
#include <Arduino.h>
Barometer ::Barometer(bool activeStatus) : active{activeStatus}
{
  if (this->isActive())
  {
    _barometer = new Adafruit_BMP280;
  }
}

Barometer ::~Barometer()
{
  if (_barometer != nullptr)
  {
    delete _barometer;
  }
}

bool Barometer::init()
{
  if (!this->isActive())
  {
    return 0;
  }

  else if (!this->_barometer->begin(this->chipAdress))
  {
    this->deactivate();
    return 0;
  }

  this->_barometer->setSampling(Adafruit_BMP280::MODE_NORMAL,  /* Operating Mode. */
                                Adafruit_BMP280::SAMPLING_X2,  /* Temp. oversampling */
                                Adafruit_BMP280::SAMPLING_X16, /* Pressure oversampling */
                                Adafruit_BMP280::FILTER_X16,   /* Filtering. */
                                Adafruit_BMP280::STANDBY_MS_500);

  return 1;
}

bool Barometer::isActive() const
{
  return this->active;
}

void Barometer::activate()
{
  if (!this->isActive())
  {
    this->_barometer = new Adafruit_BMP280;
    this->active = true;
  }
}

void Barometer::deactivate()
{
  if (this->isActive())
  {
    delete this->_barometer;
    this->active = false;
  }
}

void Barometer ::setPressure0(float value)
{
  if (this->isActive())
  {
    this->_pressure0 = value;
  }
}

float Barometer ::temperature() const
{
  if (this->isActive())
  {
    return this->_barometer->readTemperature();
  }
  else
  {
    return -1;
  }
}

float Barometer ::pressure() const
{
  if (this->isActive())
  {
    return this->_barometer->readPressure();
  }
  else
  {
    return -1;
  }
}

float Barometer ::alt() const
{
  if (this->isActive())
  {
    return this->_barometer->readAltitude(this->_pressure0);
  }
  else
  {
    return -1;
  }
}

String Barometer::getData() 
{
  if (!this->isActive())
  {
    return String("");
  }
  String aux = String('T') + String(this->temperature(), 1) + String(";P") + String(this->pressure(), 1) + String(";B") + String(this->alt(), 1) + String(';');

  return aux;
}