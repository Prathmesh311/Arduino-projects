#include<Servo.h>
int pos=0;
int servopin=9;
int servodelay=25;

Servo mypointer;

void setup() {
  // put your setup code here, to run once:
     Serial.begin(9600);
     mypointer.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:


      for(int pos=5;pos<170;pos++)
      {
        mypointer.write(pos);
        delay(servodelay);
      }

      for(pos=170;pos>5;pos--)
      {
        mypointer.write(servopin);
        delay(servodelay);
      }
}
