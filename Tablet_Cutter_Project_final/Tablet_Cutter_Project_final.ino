

#include <Servo.h>

Servo servo1;
Servo servo2;

int butPin = 12;
bool newState;
bool oldState = 1;
int count = 0;

int pos1 = 0;
int pos2 = 0;

void firstServoPos();
void secondServoPos();

void setup() {
  pinMode(butPin, INPUT);
  servo1.attach(5);
  servo2.attach(6);
  Serial.begin(9600);
  servo1.write(pos1);
  servo2.write(pos2);
}

void loop() {
  newState = digitalRead(butPin);


  
if (  count == 0 ) {
   newState = digitalRead(butPin);
  if ( newState == 0 ) {
    firstServoPos();
  }
  count++;
  delay(100);
}

newState = digitalRead(butPin);
if ( count==1  ) {
  newState = digitalRead(butPin);
  if  ( newState == 0  ) {
    secondServoPos();   
    }
    count++;
    delay(100);    
  }
count = 0;

}

void firstServoPos()
{
  for (pos1 = 0; pos1 <= 170; pos1 += 1 ) {

    servo1.write(pos1);
    delay(5);
  }
  for (pos1 = 180; pos1 >= 0; pos1 -= 1) {
    servo1.write(pos1);
    delay(5);
  }
}

void secondServoPos()
{
  for (pos2 = 0; pos2 <= 170; pos2 += 1) {
    // in steps of 1 degree
    servo2.write(pos2);
    delay(5);
  }
  for (pos2 = 180; pos2 >= 0; pos2 -= 1) {
    servo2.write(pos2);
    delay(5);
  }
}
