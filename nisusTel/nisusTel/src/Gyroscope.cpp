#include <Gyroscope.h>


Gyroscope :: Gyroscope(bool activeStatus){
    this->active = activeStatus;
    
    if(this->isActive()){
    this->_gyroscope = new MPU6050(Wire);
    // Wire.begin(21,22);
    // delay(10);
    this->_gyroscope->begin();
    delay(1000);
    this->_gyroscope->calcOffsets(true,true);
  }
}

Gyroscope :: ~Gyroscope(){
  delete this->_gyroscope;
}

bool Gyroscope::isActive() {
  return this->active;
}

void Gyroscope::activate() {
  this->active = true;
}


void Gyroscope::deactivate() {
  this->active = false;
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

