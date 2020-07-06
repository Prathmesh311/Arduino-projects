#include<Adafruit_GPS.h>
#include<SoftwareSerial.h>

SoftwareSerial mySerial(3,2);
Adafruit_GPS GPS(&mySerial);

String NMEA1;
String NMEA2;
char c;

void setup() {
  Serial.begin(112500);
  GPS.begin(9600);
  GPS.sendCommand("$PGCMD,33,0*6D");
  GPS.sendCommand(PMTK_SET_NMEA_UPDATE_10HZ);
  GPS.sendCommand(PMTK_SET_NMEA_OUTPUT_RMCGGA);
}

void loop() {
  readGPS();
  delay(250);
}

void readGPS()
{
  clearGPS();
  
  while(!GPS.newNMEAreceived())
  {
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
  NMEA1=GPS.lastNMEA();

  while(!GPS.newNMEAreceived())
  {
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
  NMEA2=GPS.lastNMEA();

  Serial.print(NMEA1);
  Serial.print(NMEA2);
  Serial.print("");
}

void clearGPS()
{
  while(!GPS.newNMEAreceived())
  {
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());

  while(!GPS.newNMEAreceived())
  {
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());

  while(!GPS.newNMEAreceived())
  {
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
}
 
