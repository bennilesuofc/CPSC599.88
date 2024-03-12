//www.elegoo.com
//2016.12.08
#include <Servo.h>

Servo servo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

String pos;
int servoPos = 0;    // variable to store the servo position
int lastServoPos = 0;// variable to store the last servo position
int dataPos = 0;    // variable to store position in data string

//data file- easier to store on Arduino than to read over Serial
String data = "44443554544455444444444455423333455555445555445555431123433344332333233344444444454444444555444555655555565554455666566677776666666666776677776666677776677777777777667766566676777777666777777777777767777787776777777777777767788787666776677777777666666666766677665666666665556665666665555656665554333444455555655555555544655555444455444445655445445545554555444545545";

/* harmonica-servo position mapping
0-0 -not using
1-30
2-45
3-60
4-75
5-90
6-105
7-120
8-140
9-155 -not using
10-185 -not using
*/
int positions[] = {0, 30, 45, 60, 75, 90, 105, 120, 140};

void setup() {
  Serial.begin(9600);
  servo.attach(9);  // attaches the servo on pin 9 to the servo object
  Serial.println(positions[1]);
  Serial.println(positions[2]);
  Serial.println(positions[3]);
  Serial.println(positions[4]);
  Serial.println(positions[5]);
  Serial.println(positions[6]);
  Serial.println(positions[7]);
  Serial.println(positions[8]);
}

//works as one big while loop- after entire data file is read, restarts from the beginning
void loop() {

  //read data from file and find corresponding servo position
  pos = data[dataPos];
  servoPos = pos.toInt();
  Serial.print("Day (DataPos): ");
  Serial.print(dataPos);
  Serial.print(", Pitch (ServoPos): ");
  Serial.print(servoPos);
  Serial.print(", Position (servo degree): ");
  Serial.println(positions[servoPos]);

  //change servo position if it is different
  if (servoPos != lastServoPos){
    servo.write(positions[servoPos]);
    Serial.println("changing servo position");
    lastServoPos = servoPos;
  }

  //wait 200ms for servo to move and note to play
  delay(200);

  //increment counter, if at end of data file reset counter
  if(dataPos<data.length()){
    dataPos++;
  }else {
    dataPos = 0;
  }
}

