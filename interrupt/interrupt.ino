#include<TimerOne.h>

String LEDstatus="OFF";
int RedPin=10;
int YellowPin=9;
void setup() {
  // put your setup code here, to run once:
  pinMode(RedPin,OUTPUT);
  pinMode(YellowPin,OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(yellowBlink);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RedPin,LOW);
  delay(250);
  digitalWrite(RedPin,HIGH);
  delay(250);
}

void yellowBlink()
{
  if(LEDstatus=="OFF")
  {
    digitalWrite(YellowPin,HIGH);
    LEDstatus="ON";
    return;
  }
  if(LEDstatus=="ON")
  {
    digitalWrite(YellowPin,LOW);
    LEDstatus="OFF";
    return;
    }
  }
