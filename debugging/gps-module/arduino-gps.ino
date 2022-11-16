#include "TinyGPS++.h"
#include "SoftwareSerial.h"

SoftwareSerial serial_connection(10, 11); //RX=pin 10, TX=pin 11
TinyGPSPlus gps;//Initialize object

void setup(){
    Serial.begin(9600);
    serial_connection.begin(9600);
    Serial.println("GPS Start:");
}

void loop(){
  while(serial_connection.available()){
    gps.encode(serial_connection.read());
  }
    if(gps.location.isUpdated()){
  
    //Get the info from the gps
    Serial.println("Satellite Count: %f", gps.satellites.value());
    Serial.println("Latitude:%.6f", gps.location.lat());
    Serial.println("Longitude:%.6f", gps.location.lng());
    Serial.println("Speed MPH:%d", gps.speed.mph());
    Serial.println("Altitude Feet:%d", gps.altitude.feet());
    Serial.println("");
  }
}
