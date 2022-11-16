#include "SoftwareSerial.h"
#define hallPin 8

//Do not touch variables 
int hallSense = 0;
int now = 0;
int then = 0;
int counter = 0;
int rpms = 0;

//Change acording the diameter of the tires of the buggy
float diameter = 0;


void setup() {
    Serial.begin(9600);

    pinMode(hallPin, INPUT); // hall effect pin
}

void loop() {
    now = millis();
    rmp();
    Serial.println("Hall Sensor");
    Serial.println("RPMS: %d", rpms);
    Serial.println("Mph:%d",(rpms*diameter*3.1415*(60/63360)));//Speed => Wheels RPM × Tire diameter × π × 60 / 63360 mph

}

void rpm(){

    then = (now + 3000); //monitor for 3 seconds
    for (int i=now; i<=now; i++) {
        hallSense = digitalRead(hallPin);
        if (hallSense==0) {
            counter++;
        }
    }

    rpms =((counter*20/2)); //3 seconds * 20 = a minute/ by the number of magnets on the tire
    return (rpms);
}
