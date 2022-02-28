#include <Barometer.h>


Barometer :: Barometer(bool activeStatus) {
    this->active = activeStatus;
    
    if(this->isActive()){
    this->_barometer = new Adafruit_BMP280;
    // Wire.begin(12,13);
    // delay(10);
    this->_barometer->begin(this->chipAdress);
  }
}

Barometer :: ~Barometer() {
    delete this->_barometer;
}

bool Barometer::isActive() {
  return this->active;
}

void Barometer::activate() {
  this->active = true;
}


void Barometer::deactivate() {
  this->active = false;
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

String Barometer::getData(){
  if(!this->isActive()){
    return String("");
  }
  String aux = String('T') + String(this->temperature(),3) + String(";P") + String(this->pressure(),3) + String(";B") + String(this->alt(),3) + String(';');
  
  return aux;
}