//CPSC 599.88 Project 3
//April 5, 2024
//Benjamin Niles
//
//code modified from https://electronics.koncon.nl/supercollider/
//and https://www.instructables.com/Capacitive-Sensing-for-Dummies/

#include <CapacitiveSensor.h>

//capacitive touch sensors

CapacitiveSensor cs_0 = CapacitiveSensor(3,2);
CapacitiveSensor cs_1 = CapacitiveSensor(5,4);
CapacitiveSensor cs_2 = CapacitiveSensor(7,6);
CapacitiveSensor cs_3 = CapacitiveSensor(9,8);
CapacitiveSensor cs_4 = CapacitiveSensor(11,10);

//capacitive touch sensor values
long cap0 = 0;
long cap1 = 0;
long cap2 = 0;
long cap3 = 0;
long cap4 = 0;

//slide potentiometer values
int slide0 = 0;
int slide1 = 0;
int slide2 = 0;
int slide3 = 0;
int slide4 = 0;

void setup() {
  Serial.begin(9600);
}

void writeValues(long cap, int slide){
  int cap_result = 0;
  if(cap > 100){
    cap_result = 1;
  }

  //map slide to some range of values too

  Serial.print(cap_result);
  Serial.print(",");
  Serial.print(slide);
  Serial.print(",");
}

void loop() {
//read from sensors
  cap0 = cs_0.capacitiveSensor(10);
  slide0 = analogRead(A5);
  delay(10);

  cap1 = cs_1.capacitiveSensor(10);
  slide1 = analogRead(A4);
  delay(10);

  cap2 = cs_2.capacitiveSensor(10);
  slide2 = analogRead(A3);
  delay(10);

  cap3 = cs_3.capacitiveSensor(10);
  slide3 = analogRead(A2);
  delay(10);

  cap4 = cs_4.capacitiveSensor(10);
  slide4 = analogRead(A1);
  delay(10);

  writeValues(cap0, slide0);
  writeValues(cap1, slide1);
  writeValues(cap2, slide2);
  writeValues(cap3, slide3);
  writeValues(cap4, slide4);

  Serial.println();
  delay(10);

}
