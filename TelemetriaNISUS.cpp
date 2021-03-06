//Implementação da biblioteca de telemetria para a equipe de competição NISUS implementada para microcontrolador ESP32
//Created by Paulo H. A. Kammradt, July 11, 2021

#include "TelemetriaNISUS.h"


//#------------------------------------------------------------------------------#
//Classe Sensor
//#------------------------------------------------------------------------------#

Sensor :: Sensor (bool activateStatus) {
  this->active = activateStatus;
  return;
}

bool Sensor :: isActive() {
  return this->active;
}

void Sensor :: activate() {
  this->active = true;
}


void Sensor :: deactivate() {
  this->active = false;
}

//#------------------------------------------------------------------------------#
//Classe Gps
//#------------------------------------------------------------------------------#

Gps :: Gps (bool activeStatus) : Sensor(activeStatus) {
  if(this->isActive()){
    this->_gps = new TinyGPSPlus;
  }
}

Gps :: ~Gps() {
  delete this->_gps;
}

int Gps :: nSatellites(){
  if(this->isActive()){
    return this->_gps->satellites.value();
  }
  else{
    return -1;
  }
}

float Gps :: alt(){
  if(this->isActive()){
    return this->_gps->altitude.meters();
  }
  else{
    return -999;
  }
}

float Gps :: speed(){
 if(this->isActive()){
    return this->_gps->speed.kmph();
  }
  else{
    return -1;
  } 
}

double Gps :: gpsHDOP(){
  if(this->isActive()){
    return this->_gps->hdop.hdop();
  }
  else{
    return -1;
  }
}

double Gps :: lat(){
  if(this->isActive()){
    return this->_gps->location.lat();
  }
  else{
    return -1;
  }
}

double Gps :: lon(){
  if(this->isActive()){
    return this->_gps->location.lng();
  }
  else{
    return -1;
  }
}

void Gps :: getData(double* _lat, double* _lon, float* _alt, float* _speed, int* _nSatellites, double* _gpsHdop){
   if(!this->isActive()){
    return;
  }
  if(_lat != nullptr){
    *_lat = this->lat();
  }
  if(_lon != nullptr){
    *_lon = this->lon();
  }
  if(_alt != nullptr){
    *_alt = this->alt();
  }
  if(_speed != nullptr){
    *_speed = this->speed();
  }
  if(_nSatellites != nullptr){
    *_nSatellites = this->nSatellites();
  }
  if(_gpsHdop != nullptr){
    *_gpsHdop = this->gpsHDOP();
  }
}

//#------------------------------------------------------------------------------#
//Classe Barometro
//#------------------------------------------------------------------------------#

Barometer :: Barometer(bool activeStatus) : Sensor(activeStatus) {
    if(this->isActive()){
    this->_barometer = new Adafruit_BMP280;
    Wire.begin(12,13);
    delay(10);
    this->_barometer->begin(0x76);
  }
}

Barometer :: ~Barometer() {
    delete this->_barometer;
}

void Barometer :: setPressure0(float value){
   if(this->isActive()){
    this->_pressure0 = value;
  }
}


float Barometer :: temperature(){
   if(this->isActive()){
    return this->_barometer->readTemperature();
  }else{
    return -1;
  }
}

float Barometer :: pressure(){
   if(this->isActive()){
    return this->_barometer->readPressure();
  }else{
    return -1;
  }
}


float Barometer :: alt(){
  if(this->isActive()){
    return this->_barometer->readAltitude(this->_pressure0);
  }else{
    return -1;
  }
}

void Barometer :: getData(float* _pressure, float* _temperature, float* _alt){
  if(!this->isActive()){
    return;
  }
  if(_pressure != nullptr){
    *_pressure = this->pressure();
  }
  if(_temperature != nullptr){
    *_temperature = this->temperature();
  }
  if(_alt != nullptr){
    *_alt = this->alt();
  }
}

//#------------------------------------------------------------------------------#
//Classe Giroscópio
//#------------------------------------------------------------------------------#

Gyroscope :: Gyroscope(bool activeStatus) : Sensor(activeStatus){
    if(this->isActive()){
    this->_gyroscope = new MPU6050(Wire);
    Wire.begin(21,22);
    delay(10);
    this->_gyroscope->begin();
    delay(1000);
    this->_gyroscope->calcOffsets(true,true);
  }
}

Gyroscope :: ~Gyroscope(){
  delete this->_gyroscope;
}

void Gyroscope :: update(){
  if(!this->isActive()){
    return;
  }

  this->_gyroscope->update();
}

float Gyroscope :: pitch(){
  if(!this->isActive()){
    return -1 -1;
  }

  return this->_gyroscope->getAngleX();
}

float Gyroscope :: roll(){
  if(!this->isActive()){
    return -1;
  }

  return this->_gyroscope->getAngleY();
}

float Gyroscope :: yaw(){
  if(!this->isActive()){
    return -1;
  }

  return this->_gyroscope->getAngleZ();
}

float Gyroscope :: accX(){
  if(!this->isActive()){
    return -1;
  }

  return this->_gyroscope->getAccX();
}

float Gyroscope :: accY(){
  if(!this->isActive()){
    return -1;
  }

  return this->_gyroscope->getAccY();
}

float Gyroscope :: accZ(){
  if(!this->isActive()){
    return -1;
  }

  return this->_gyroscope->getAccZ();
}

void Gyroscope :: getData(float* _pitch, float* _roll, float* _yaw, float* _accX, float* _accY, float* _accZ){
   if(!this->isActive()){
    return;
  }
  if(_pitch != nullptr){
    *_pitch = this->pitch();
  }
  if(_roll != nullptr){
    *_roll = this->roll();
  }
  if(_yaw != nullptr){
    *_yaw = this->yaw();
  }
  if(_accX != nullptr){
    *_accX = this->accX();
  }
  if(_accX != nullptr){
    *_accY = this->accY();
  }
  if(_accX != nullptr){
    *_accZ = this->accZ();
  }
}