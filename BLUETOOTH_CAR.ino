#include <AFMotor.h>

//initial motors pin

  AF_DCMotor motor1(1);
  AF_DCMotor motor2(2);
  AF_DCMotor motor3(3);
  AF_DCMotor motor4(4);
  char command; 

void setup() 
{      
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255); 
  Serial.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop(){
  if(Serial.available() > 0){ 
    command = Serial.read(); 
    Stop(); //initialize with motors stoped
    //switch statement takes user input and activates methods
    Serial.println(command);
    switch(command){
    case 'F':  
      forward();
      //delay(1000);
      break;
    case 'B':  
       back();
       //delay(1000);
      break;
    case 'L':  
      left();
      //delay(1000);
      break;
    case 'R':
      right();
      //delay(1000);
      break;
    }
  } 
}

//method to go forward
void forward()
{

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

}

//method to go backwards
void back()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}

//method to turn left
void left()
{
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

}

//method to turn right
void right()
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
} 

//stops all motors
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}
