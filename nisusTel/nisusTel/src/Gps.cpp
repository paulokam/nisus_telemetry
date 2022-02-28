#include <Gps.h>


Gps :: Gps(bool activeStatus){
  this->active = activeStatus;
  
  if(this->isActive())
    this->_gps = new TinyGPSPlus;
}

Gps :: ~Gps() {
  delete this->_gps;
}

bool Gps::isActive() {
  return this->active;
}

void Gps::activate() {
  this->active = true;
}


void Gps::deactivate() {
  this->active = false;
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
    return -1;
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

//ALTERAR
String Gps :: getData(){
   if(!this->isActive()){
    return String("");
  }

  String aux = String('A') + String(this->lat(),3) + String(";O") + String(this->lon(),3) + String(";S") + String(this->speed(),3) + String(";H") + String(this->alt()) 
            + String(";N") + String(this->nSatellites(),DEC) + String(';');
  
  return aux;
}
