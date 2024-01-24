//CPSC 599.88 Project 0
//Jan 25, 2024
//Benjamin Niles

//Code based off of ELegoo Arduino Lesson 4 RGB LED, and Lesson 12 Analog Joystick Module

// pins for joystick
const int SW_pin = 2; // digital pin connected to switch output
const int X_pin = A0; // analog pin connected to X output
const int Y_pin = A1; // analog pin connected to Y output

//pins for upper led
const int U_red = 10;
const int U_green = 9;
const int U_blue = 8;

//pins for lower led
const int L_red = 6;
const int L_green = 5;
const int L_blue = 3;


void setup() {
  //set up joystick button
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);

  //set up LEDs
  pinMode(U_red, OUTPUT);
  pinMode(U_green, OUTPUT);
  pinMode(U_blue, OUTPUT);
  digitalWrite(U_red, HIGH);
  digitalWrite(U_green, LOW);
  digitalWrite(U_blue, LOW);

  pinMode(L_red, OUTPUT);
  pinMode(L_green, OUTPUT);
  pinMode(L_blue, OUTPUT);
  digitalWrite(L_red, LOW);
  digitalWrite(L_green, LOW);
  digitalWrite(L_blue, LOW);

  Serial.begin(9600);
}

int xValue, yValue, buttonValue;
int l_redValue, l_greenValue, l_blueValue = 0;


void loop() {
  //swap x and y axes, and flip x axis to match physical orientation of joystick
  xValue = -map(analogRead(Y_pin), 0, 1023, -10, 10);
  yValue = map(analogRead(X_pin), 0, 1023, -10, 10);
  buttonValue = digitalRead(SW_pin);

  Serial.print("Switch:  ");
  Serial.println(buttonValue);
  Serial.print("X-axis: ");
  Serial.println(xValue);
  Serial.print("Y-axis: ");
  Serial.println(yValue);

//colour adjustment
  if(digitalRead(U_red) == HIGH){
    l_redValue += xValue;
    if(l_redValue > 255) l_redValue = 255;
    if(l_redValue < 0) l_redValue = 0;
  }
  else if (digitalRead(U_green) == HIGH){
    l_greenValue += xValue;
    if(l_greenValue > 255) l_greenValue = 255;
    if(l_greenValue < 0) l_greenValue = 0;
  }
  else if (digitalRead(U_blue) == HIGH){
    l_blueValue += xValue;
    if(l_blueValue > 255) l_blueValue = 255;
    if(l_blueValue < 0) l_blueValue = 0;
  }

//switch between r>g>b>r
  if(yValue >9){
   if(digitalRead(U_red) == HIGH){
   digitalWrite(U_red, LOW);
   digitalWrite(U_green, HIGH);
   }
   else if (digitalRead(U_green) == HIGH){
    digitalWrite(U_green, LOW);
    digitalWrite(U_blue, HIGH);
   }
   else if (digitalRead(U_blue) == HIGH){
    digitalWrite(U_blue, LOW);
    digitalWrite(U_red, HIGH);
   }
  }

//switch between r<g<b<r
  if(yValue <-9){
   if(digitalRead(U_red) == HIGH){
    digitalWrite(U_red, LOW);
    digitalWrite(U_blue, HIGH);
   }
   else if (digitalRead(U_green) == HIGH){
    digitalWrite(U_green, LOW);
    digitalWrite(U_red, HIGH);
   }
   else if (digitalRead(U_blue) == HIGH){
    digitalWrite(U_blue, LOW);
    digitalWrite(U_green, HIGH);
   }
  }

//random colour if button is pressed
  if(buttonValue == 0){
    l_redValue = random(0, 255);
    l_greenValue = random(0, 255);
    l_blueValue = random(0, 255);
  }

//display the new colour
  analogWrite(L_red, l_redValue);
  analogWrite(L_green, l_greenValue);
  analogWrite(L_blue, l_blueValue);

  delay(200);
}
