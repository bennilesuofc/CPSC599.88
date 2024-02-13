//CPSC 599.88 Project 1
//Feb 13, 2024
//Benjamin Niles
//
//code modified from https://electronics.koncon.nl/supercollider/

//photoresistor values
int photo0 = 0;
int photo1 = 0;
int photo2 = 0;
int photo3 = 0;
int photo4 = 0;

//slide potentiometer values
int pot0 = 0;
int pot1 = 0;
int pot2 = 0;
int pot3 = 0;
int pot4 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
}

/*function code from https://arduino.stackexchange.com/questions/29074/use-photocell-as-digital-input
 *
 * Read the given pin avoiding the input hysteresis.
 *
 * Returns HIGH if the pin voltage is above the upper (LOW to HIGH)
 * threshold, LOW otherwise.
 *
 * WARNING: The pin is set to OUTPUT LOW for a very short time.
 */
int anhystereticRead(uint8_t pin) {
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
    pinMode(pin, INPUT);
    //flip result so that a lack of light sends a "1" to supercollider
    return !digitalRead(pin);
}


void loop() {

    //read each digital and analog input
    photo0 = anhystereticRead(6);
    pot0 = analogRead(A0);
    delay(10); 
    
    photo1 = anhystereticRead(5);
    pot1 = analogRead(A1);
    delay(10); 
 
 //3 and 4 are switched for some reason, probably a wiring error
    photo2 = anhystereticRead(3);
    pot2 = analogRead(A2);
    delay(10); 

    photo3 = anhystereticRead(4);
    pot3 = analogRead(A3);
    delay(10); 

    photo4 = anhystereticRead(2);
    pot4 = analogRead(A4);
    delay(10); 

    // below will serial print an array of values to be interpreted by supercollider
    Serial.print(photo0);
    Serial.print(","); 
    Serial.print(pot0);
    Serial.print(","); 

    Serial.print(photo1);
    Serial.print(","); 
    Serial.print(pot1);
    Serial.print(","); 

    Serial.print(photo2);
    Serial.print(","); 
    Serial.print(pot2);
    Serial.print(","); 

    Serial.print(photo3);
    Serial.print(","); 
    Serial.print(pot3);
    Serial.print(","); 

    Serial.print(photo4);
    Serial.print(","); 
    Serial.println(pot4);
}