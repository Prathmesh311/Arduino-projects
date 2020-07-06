#include<LiquidCrystal.h>
LiquidCrystal LCD(10,9,7,6,5,3,2);

int trigpin=13;
int echopin=11;
float speedOfSound=776.5;
float pingtime;
float targetDistance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("target distance:");

  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigpin,LOW);
  delayMicroseconds(2000);
  digitalWrite(trigpin,HIGH);
  delayMicroseconds(15);
  digitalWrite(trigpin,LOW);

  pingtime=pulseIn(echopin,HIGH);
  pingtime=pingtime/(1000000*3600);
  
  targetDistance=(speedOfSound*pingtime)/2;
  targetDistance=targetDistance*63360;

  LCD.setCursor(0,1);
  LCD.print("                ");
  LCD.setCursor(0,1);
  LCD.print(targetDistance);
  LCD.print("inches");
  delay(250);
  
}
