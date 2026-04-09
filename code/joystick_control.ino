//-------------------------------------------------------------
//Note circuit must be complete with battery pack
//DONT TRY TO PLUG IN BOTH MICOCONTROLLER USB AND BATTERY PACK!!
//ONLY USB WILL NOT GIVE ENOUGH POWER TO OPERATE
//--------------------------------------------------------------------
#include <Servo.h>   // lets us control servos

// -------- Servo objects --------
Servo servo1;   // base
Servo servo2;   // shoulder
Servo servo3;   // middle
Servo servo4;   // wrist
Servo servo5;   // claw


// -------- Joystick 1 pins --------
#define JOY1_X A1
#define JOY1_Y A0
#define JOY1_SW 7

// -------- Joystick 2 pins --------
#define JOY2_X A3
#define JOY2_Y A4
#define JOY2_SW 12

// -------- Thresholds --------
#define LOW_THRESHOLD  400
#define HIGH_THRESHOLD 800

// -------- Variables to store joystick values --------
int joy1X = 0;
int joy1Y = 0;
int joy2X = 0;
int joy2Y = 0;

// -------- Starting servo positions --------
int pos1 = 120;   // base
int pos2 = 90;    // shoulder
int pos3 = 100;    // middle
int pos4 = 90;    // wrist
int pos5 = 0;     // claw

void setDefault() {
  servo1.write(pos1);
  servo2.write(pos2);
  servo3.write(pos3);
  servo4.write(pos4);
  servo5.write(pos5);
}

void setup() {
  Serial.begin(9600);

  // attach servos
  servo1.attach(9);
  servo2.attach(6);
  servo3.attach(5);
  servo4.attach(3);
  servo5.attach(11);

  // joystick buttons use pull-up
  pinMode(JOY1_SW, INPUT_PULLUP);
  pinMode(JOY2_SW, INPUT_PULLUP);

  setDefault();
}

void loop() {
  // -------- Read joystick values --------
  joy1X = analogRead(JOY1_X);
  joy1Y = analogRead(JOY1_Y);
  joy2X = analogRead(JOY2_X);
  joy2Y = analogRead(JOY2_Y);

  //---------------------
  // JOYSTICK 1 CONTROLS
  // Example:
  // X controls base
  // Y controls shoulder
  //-----------------------

  // Move base left
  if (joy1X < LOW_THRESHOLD) {
    pos1 = pos1 + 1;          // increase angle slowly
    if (pos1 > 180) pos1 = 180;
    servo1.write(pos1);
  }

  // Move base right
  else if (joy1X > HIGH_THRESHOLD) {
    pos1 = pos1 - 1;          // decrease angle slowly
    if (pos1 < 0) pos1 = 0;
    servo1.write(pos1);
  }

  // Move shoulder up
  if (joy1Y < LOW_THRESHOLD) {
    pos2 = pos2 + 1;
    if (pos2 > 180) pos2 = 180;
    servo2.write(pos2);
  }

  // Move shoulder down
  else if (joy1Y > HIGH_THRESHOLD) {
    pos2 = pos2 - 1;
    if (pos2 < 0) pos2 = 0;
    servo2.write(pos2);
  }

  // -----------------------------------
  // JOYSTICK 2 CONTROLS
  // Example:
  // X controls middle joint
  // Y controls wrist
  // ------------------------------------

  // Move middle joint
  if (joy2X < LOW_THRESHOLD) {
    pos3 = pos3 + 1;
    if (pos3 > 180) pos3 = 180;
    servo3.write(pos3);
  }

  else if (joy2X > HIGH_THRESHOLD) {
    pos3 = pos3 - 1;
    if (pos3 < 0) pos3 = 0;
    servo3.write(pos3);
  }

  // Move wrist
  if (joy2Y < LOW_THRESHOLD) {
    pos4 = pos4 + 1;
    if (pos4 > 180) pos4 = 180;
    servo4.write(pos4);
  }

  else if (joy2Y > HIGH_THRESHOLD) {
    pos4 = pos4 - 1;
    if (pos4 < 0) pos4 = 0;
    servo4.write(pos4);
  }

  // -------------------------
  // BUTTONS
  // ---------------------------

  // Joystick 1 button closes claw while pressed
  if (digitalRead(JOY1_SW) == LOW) {                             
    servo5.write(90);   // close claw
  } else {
    servo5.write(0);    // open claw
  }

   //Joystick 2 button can reset arm to default
  if (digitalRead(JOY2_SW) == LOW) {
    pos1 = 120;
    pos2 = 90;
    pos3 = 90;
    pos4 = 90;
    pos5 = 0;
    setDefault();
    Serial.println("Arm reset to default");
    delay(3000);   // debounce
  }

  delay(15);   // smoother motion
}
