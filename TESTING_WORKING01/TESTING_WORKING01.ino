#include <Servo.h>

//Globals
#define STEPPIN 4
#define DIRPIN 3
#define ENAPIN 10
#define servo_ 7
int stepper_speed_ = 5;
int servo_speed = 5;
int pos = 0;

Servo myservo;

const int STEPTIME = 1;
void setup() {
  myservo.attach(servo_);
  pinMode(servo_, OUTPUT);
  // put your setup code here, to run once:
  pinMode(STEPPIN, OUTPUT);
  pinMode(DIRPIN, OUTPUT);
  pinMode(ENAPIN, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  forward(220);

}

void forward(int steps) {

  for (pos = 0; pos <= 110; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(servo_speed);                       // waits 15ms for the servo to reach the position
  }

  delay(1000); // opening time between servo and stepper

  int i;
  digitalWrite(ENAPIN, LOW); //ENABLE IS ACTIVE LOW
  digitalWrite(DIRPIN, HIGH); //SET DIRECTION
  for (i = 0; i < steps; i++) {
    digitalWrite(STEPPIN, HIGH);
    delay(STEPTIME);
    digitalWrite(STEPPIN, LOW);
    delay(STEPTIME);
    delay(stepper_speed_);
  }
  digitalWrite(ENAPIN, HIGH); //DISABLE STEPPER
  delay(500); // closing time between servo and stepper

  for (pos = 110; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(servo_speed);                       // waits 15ms for the servo to reach the position
  }

  delay(500);

  digitalWrite(ENAPIN, LOW); //ENABLE IS ACTIVE LOW
  digitalWrite(DIRPIN, LOW); //SET DIRECTION
  for (i = 0; i < 20; i++) {
    digitalWrite(STEPPIN, HIGH);
    delay(STEPTIME);
    digitalWrite(STEPPIN, LOW);
    delay(STEPTIME);
    delay(stepper_speed_);
  }
  delay(1000);
}