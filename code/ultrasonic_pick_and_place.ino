// Ultrasonic-triggered robotic arm routine
// This module uses HC-SR04 distance readings to trigger
// predefined servo movement sequences for object pickup
// and release at different detected distances.


#include <Servo.h>
Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;

//90 is closed and 0 is open 180 is maxed closed for servo5(Claw)
//0 is clockwise,180 counter-clockwise,90 is deafult servo4(Wrist)
//0 is backward, 70-90 is straight up, and 180 is backwards Servo 3(Elbow)
//0 max bend backwards,180 max bend foward,90 is straight up (Shoulder)
//0 is adruino facing,90 is front facing,180 is full left 120 default setting (Rotater Cuff)

int trigPin = 2;//attach pin 5 trig;
int echoPin = 4;//attach pin 6 echo;
int distanceCm = 0;
int threshold1 = 10;//setting it for 10 cm from arm
int threshold2 = 15;

void setDefault(){
  //Default Arm placement
  servo1.write(120);
  servo2.write(90);
  servo3.write(100);
  servo4.write(90);
  servo5.write(0);
}
void setup()
{
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);

  servo1.attach(9);//Bottom
  servo2.attach(6);//Shoulder
  servo3.attach(5);//Middle
  servo4.attach(3);//
  servo5.attach(11);//Claw
  setDefault(); 
}
void loop()
{
  long duration,inches,cm;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  duration=pulseIn(echoPin,HIGH);

  inches=microsecondsToInches(duration);
  cm= microsecondsToCentimeters(duration);

  Serial.print(inches);
  Serial.print("in,");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
//for 10cm
if (cm <= threshold1 ){
  //static bool ran = false;
  //if (ran) return; //stop repeating
  //ran = true;


  setDefault();
  delay(1000);

  servo3.write(0);
  servo2.write(160);
  delay(1000);

  //next movement after defaut:
  servo5.write(90);//claw close
   delay(1000);

  servo2.write(90);
  delay(1000);

  servo1.write(180);
  delay(1000);

  servo5.write(0);
  delay(1000);
  
  servo1.write(90);
  delay(1000);

  setDefault();
  delay(1000);





}
//for 15cm
if(cm == threshold2){
   static bool ran = false;
  if (ran) return; //stop repeating
  ran = true;


  setDefault();
  delay(1000);

  servo3.write(90);
  servo2.write(180);
  delay(1000);

  //next movement after defaut:
  
  servo3.write(50);
  delay(1000);
  
  servo5.write(90);//claw close
  delay(1000);

  servo3.write(100);
  delay(1000);

  servo1.write(180);
  delay(1000);

  servo5.write(0);
  delay(1000);

  servo1.write(90);
  delay(1000);

  setDefault();
  delay(1000);
}
else{ setDefault();

}
  delay(100);


  
}

long microsecondsToInches(long microseconds)

{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)

{
  return microseconds / 29/ 2;
}
