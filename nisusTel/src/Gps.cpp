#include <Gps.h>
#include <Arduino.h>

Gps ::Gps(bool activeStatus) : active{activeStatus}
{
  if (this->isActive())
    this->_gps = new TinyGPSPlus;
}
Gps ::~Gps()
{
  if (_gps != nullptr)
  {
    delete this->_gps;
  }
}

bool Gps ::init()
{
  if (this->isActive())
  {
    Serial1.begin(this->baudRate, SERIAL_8N1, this->RXPin, this->TXPin);
    return 1;
  }
  else
  {
    return 0;
  }
}

void Gps::update()
{
  if (this->isActive())
  {
    this->_gps->encode(Serial1.read());
  }
}

/**
 * @brief Retorna status do sensor
 *
 * @return true se ativado
 * @return false se desativado
 */
bool Gps::isActive() const
{
  return this->active;
}

/**
 * @brief Ativa Gps se desativado
 *
 */
void Gps::activate()
{
  if (!this->isActive())
  {
    this->_gps = new TinyGPSPlus;
    this->active = true;
  }
}

/**
 * @brief Desativa Gps se ativado
 *
 */
void Gps::deactivate()
{
  if (!this->isActive())
  {
    delete _gps;
    this->active = false;
  }
}

/**
 * @brief Retorna número de satélites pareados pelo Gps se ativo
 *
 * @return int
 */
int Gps ::nSatellites() const
{
  if (this->isActive())
  {
    return this->_gps->satellites.value();
  }
  else
  {
    return -1;
  }
}

/**
 * @brief Retorna altitude lida pelo Gps se ativo
 *
 * @return float
 */
float Gps ::alt() const
{
  if (this->isActive())
  {
    return this->_gps->altitude.meters();
  }
  else
  {
    return -1;
  }
}

/**
 * @brief Retorna velocidade lida pelo Gps se ativo
 *
 * @return float
 */
float Gps ::speed() const
{
  if (this->isActive())
  {
    return this->_gps->speed.kmph();
  }
  else
  {
    return -1;
  }
}

/**
 * @brief Retorna HDOP lido pelo Gps se ativo
 *
 * @return double
 */
double Gps ::gpsHDOP() const
{
  if (this->isActive())
  {
    return this->_gps->hdop.hdop();
  }
  else
  {
    return -1;
  }
}

/**
 * @brief Retorna latitude lida pelo Gps se ativo
 *
 * @return double
 */
double Gps ::lat() const
{
  if (this->isActive())
  {
    return this->_gps->location.lat();
  }
  else
  {
    return -1;
  }
}

/**
 * @brief Retorna longitude lida pelo Gps se ativo
 *
 * @return double
 */
double Gps ::lon() const
{
  if (this->isActive())
  {
    return this->_gps->location.lng();
  }
  else
  {
    return -1;
  }
}

String Gps ::getData() const
{
  if (!this->isActive() || this->nSatellites() <= 0)
  {
    return String("");
  }

  String aux = "";

  String('A') + String(this->lat(), 3) + String(";O") + String(this->lon(), 3) + String(";S") + String(this->speed(), 3) + String(";H") + String(this->alt()) + String(";N") + String(this->nSatellites(), DEC) + String(';');

  return aux;
}
