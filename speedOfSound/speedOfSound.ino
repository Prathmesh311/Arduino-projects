int trigpin=13;  //pin 10 set for trigpin
int echopin=11;  //pin 11 set for echopin
float targetDistance=6;  //target distance set for 6
float pingtime;  //variable set for time 
float speedOfSound;  //variable set for speed of sound
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);   //turn on serial port
  pinMode(trigpin,OUTPUT);   //trigpin set for output
  pinMode(echopin,INPUT);  //echopin set for input
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(trigpin,HIGH);
  delayMicroseconds(2000);   //delay is set for output pin
  digitalWrite(trigpin,LOW);
  delayMicroseconds(15);   //delay is for output pin
  digitalWrite(trigpin,LOW);

  pingtime=pulseIn(echopin,HIGH);  //pingtime detected for echopin at high

  Serial.print(pingtime);

  Serial.print("   ");

  speedOfSound=2*targetDistance/pingtime;  //speed of sound in inches and microseconds 
  speedOfSound=speedOfSound/63360*1000000*3600;   //speed of sound in miles per hour
   Serial.print("speed of sound is");
   Serial.print(speedOfSound);
   Serial.println("in miles per hours");
   delay(3000);
}
