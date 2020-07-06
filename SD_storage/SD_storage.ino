#include<SD.h>
#include<SPI.h>

#include"Wire.h"
#include"Adafruit_BMP085.h"

Adafruit_BMP085 mySensor;

float tempC;
float tempF;
float pressure;

int chipselect=4;
File mySensorData; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mySensor.begin();

  pinMode(10,OUTPUT);
  SD.begin(chipselect);
}

void loop() {
  // put your main code here, to run repeatedly:
  tempC=mySensor.readTemperature();
  tempF=tempC*1.8/32;
  pressure=mySensor.readPressure();

  mySensoreData=SD.open("PTdata.txt",FILE_WRITE);

  if(mySensoreData)
  {
    Serial.print("the temperature is:");
    Serial.print(tempF);
    Serial.println("degree f");
    Serial.print("the pressure is:");
    Serial.print(pressure);
    Serial.println("pa");
    delay(1000);

    mySensoreData.print(tempF);
    mySensorData.print(",");
    mySensorData.println(pressure);
    
  }
}
