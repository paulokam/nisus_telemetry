#include <Gyroscope.h>
#include <Wire.h>

Gyroscope ::Gyroscope(bool activeStatus) : active{activeStatus}
{
  if (this->isActive())
  {
    this->_gyroscope = new MPU6050(Wire);
    // this->_gyroscope->calcOffsets(true, true);
  }
}

Gyroscope ::~Gyroscope()
{
  if (_gyroscope != nullptr)
  {
    delete this->_gyroscope;
  }
}

bool Gyroscope::isActive() const
{
  return this->active;
}

bool Gyroscope::activate()
{
  if (!this->isActive())
  {
    this->_gyroscope = new MPU6050(Wire);
    this->active = true;
    return 1;
  }
  else
    return 0;
}

bool Gyroscope::deactivate()
{
  if (this->isActive())
  {
    delete this->_gyroscope;
    this->active = false;
    return 1;
  }
  else
    return 0;
}

bool Gyroscope::init()
{

  if (!this->isActive())
  {
    return 0;
  }

  else if (this->_gyroscope->begin() != 0)
  {
    this->deactivate();
    return 0;
  }
  this->_gyroscope->calcOffsets(true, true);

  return 1;
}

void Gyroscope ::update()
{
  if (!this->isActive())
  {
    return;
  }

  this->_gyroscope->update();
}

float Gyroscope ::pitch()
{
  if (!this->isActive())
  {
    return -1 - 1;
  }

  return this->_gyroscope->getAngleX();
}

float Gyroscope ::roll()
{
  if (!this->isActive())
  {
    return -1;
  }

  return this->_gyroscope->getAngleY();
}

float Gyroscope ::yaw()
{
  if (!this->isActive())
  {
    return -1;
  }

  return this->_gyroscope->getAngleZ();
}

float Gyroscope ::accX()
{
  if (!this->isActive())
  {
    return -1;
  }

  return this->_gyroscope->getAccX();
}

float Gyroscope ::accY()
{
  if (!this->isActive())
  {
    return -1;
  }

  return this->_gyroscope->getAccY();
}

float Gyroscope ::accZ()
{
  if (!this->isActive())
  {
    return -1;
  }

  return this->_gyroscope->getAccZ();
}

String Gyroscope ::getData()
{
  if (!this->isActive())
  {
    return String("");
  }
  String aux = String('X') + String(this->pitch(), 1) + String(";Y") + String(this->roll(), 1) + String(";K") + String(this->accX(), 1) + String(";W") + String(this->accY(), 1) + String(';');

  return aux;
}
