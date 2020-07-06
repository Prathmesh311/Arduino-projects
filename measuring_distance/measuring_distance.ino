#include<Servo.h>  //load the Servo liabrary

int trigpin=13;  //trigpin set to arduino pin 13
int echopin=11;  //echopin set to arduino pin 11
int servopin=6;  //servopin set to arduino pin 6


float speedOfSound=776.5;  //speed of sound in miles per hour
float targetDistance;
float pingtime;
float servoangle;

Servo myPointer;   //create servo object called mypointer

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);  //turn on serial port
  pinMode(trigpin,OUTPUT);  //trigpin set to output
  pinMode(echopin,INPUT);   //echopin set to input
  pinMode(servopin,OUTPUT);

  myPointer.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigpin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigpin,LOW);

  pingtime=pulseIn(echopin,HIGH);  
  pingtime=pingtime/1000000; //convert pingTime to seconds by dividing by 1000000 (microseconds in a second)
  pingtime=pingtime/3600; //convert pingtime to hourse by dividing by 3600 (seconds in an hour)
  targetDistance= speedOfSound * pingtime;  //This will be in miles, since speed of sound was miles per hour
  targetDistance=targetDistance/2; //Remember ping travels to target and back from target, so you must divide by 2 for actual target distance.
  targetDistance= targetDistance*63360;    

  


  Serial.print("distance of target is: ");
  Serial.print(targetDistance);
  Serial.println("inches");
  delay(2000);

  servoangle=30;
  servoangle=servoangle+(targetDistance*15);
  myPointer.write(servoangle);
  
}
