#include <NewPing.h>
#include <Servo.h>

// MOTOR PINS 
const int LeftMotorForward = 3;
const int LeftMotorBackward = 6;
const int RightMotorForward = 5;  
const int RightMotorBackward = 11; 

#define trig_pin A1
#define echo_pin A2
#define AO_PIN A0 

#define maximum_distance 200
int distance = 100;
boolean isMoving = false;
int speedLimit = 200; 

NewPing sonar(trig_pin, echo_pin, maximum_distance); 
Servo servo_motor; 

void setup() {
  Serial.begin(9600);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  
  servo_motor.attach(8); 
  servo_motor.write(115);
  
  moveStop();
  delay(2000); 
}

void loop() {
  if(analogRead(AO_PIN) > 500) { moveStop(); return; }

  distance = readPing();

  if (distance <= 25) {
    moveStop();
    delay(300);
    moveBackward();
    delay(500);
    moveStop();
    
    int dr = lookRight();
    int dl = lookLeft();

    if (dr >= dl) turnRight(); else turnLeft();
    
    moveStop();
    delay(300);
  } else {
    if (!isMoving) {
      moveForward();
    }
  }
}


void moveForward() {
  isMoving = true;
  analogWrite(LeftMotorBackward, 0);
  analogWrite(RightMotorForward, 0); 
 
  analogWrite(LeftMotorForward, speedLimit);
  delay(50); 
  analogWrite(RightMotorBackward, speedLimit); 
}

void moveBackward() {
  isMoving = false;
  analogWrite(LeftMotorForward, 0);
  analogWrite(RightMotorBackward, 0); 
  
  analogWrite(LeftMotorBackward, speedLimit);
  analogWrite(RightMotorForward, speedLimit); 
}

void turnRight() {
  isMoving = false;
  analogWrite(LeftMotorForward, speedLimit);
  analogWrite(RightMotorForward, speedLimit); 
  analogWrite(LeftMotorBackward, 0);
  analogWrite(RightMotorBackward, 0);
  delay(600);
}

void turnLeft() {
  isMoving = false;
  analogWrite(LeftMotorBackward, speedLimit);
  analogWrite(RightMotorBackward, speedLimit);
  analogWrite(LeftMotorForward, 0);
  analogWrite(RightMotorForward, 0);
  delay(600);
}

void moveStop() {
  isMoving = false;
  analogWrite(LeftMotorForward, 0);
  analogWrite(LeftMotorBackward, 0);
  analogWrite(RightMotorForward, 0);
  analogWrite(RightMotorBackward, 0);
}


int readPing() {
  delay(70);
  int cm = sonar.ping_cm();
  return (cm == 0) ? 250 : cm;
}

int lookRight() { 
  servo_motor.write(50); 
  delay(500); 
  int d = readPing(); 
  servo_motor.write(115); 
  return d; 
}

int lookLeft() { 
  servo_motor.write(170); 
  delay(500); 
  int d = readPing(); 
  servo_motor.write(115); 
  return d; 
}