#include<TimerOne.h>
#include<SoftwareSerial.h>
int flag=0;
int RedLED=9;
long tmr;
String NMEA="";
char c;
String UPDATE_10_sec="$PMTK220,10000*2F\r\n";
String GPRMS_ONLY="PTMK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*29\r\n";
SoftwareSerial GPSSerial(2,3);

void setup() {
  // put your setup code here, to run once:
  pinMode(RedLED,OUTPUT);
  GPSSerial.begin(9600);
  Serial.begin(112500);
  delay(100);
  GPSSerial.print(GPRMS_ONLY);
  delay(100);
  GPSSerial.print(UPDATE_10_sec);
  Timer1.initialize(1000);
  Timer1.attachInterrupt(readGPS);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RedLED,HIGH);
  delay(1000);
  digitalWrite(RedLED,LOW);
  delay(1000);

  if(flag=1)
  {
    Timer1.stop();
    NMEA.trim();
    Serial.println(NMEA);
    flag=0;
    Timer1.restart();
  }
  
}

void readGPS()
{
  if(GPSSerial.available()>0)
  {
    c=GPSSerial.read();
    NMEA.concat(c);
  }
  if(c=='\r')
  {
    flag=1;
  }
}
