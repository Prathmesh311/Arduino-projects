int RedLEDpin=9;
int YellowLEDpin=10;
int numRedblinkes=5;
int numYellowblinkes=5;
int Redontime=250;
int Redofftime=250;
int Yellowontime=250;
int Yellowofftime=250;
String Redmassage="Red LED is Blinking";
String Yellowmassage="Yellow LED is blinking";
int RedLEDnum;
int YellowLEDnum;
void setup() {
  
  Serial.begin(112500);
  pinMode(RedLEDpin,OUTPUT);
  pinMode(YellowLEDpin,OUTPUT);


  Serial.print("enter the number of Red (0-255)?");
  while(Serial.available()==0){}
  RedLEDnum=Serial.parseInt();


  Serial.print("Enter the number of Yellow(0-255)?");
  while(Serial.available()==0)
  YellowLEDnum=Serial.parseInt();

}

void loop() {
  int j=0;
  while (j<=numRedblinkes){
    Serial.print(j);
    Serial.print(Redmassage);
    digitalWrite(RedLEDpin,RedLEDnum);
    delay(Redontime);
    digitalWrite(RedLEDpin,0);
    delay(Redofftime);
    j=j+1;
    
    
  }
  while(j<=numYellowblinkes){
    Serial.print(j);
    Serial.print(Yellowmassage);
    digitalWrite(RedLEDpin,YellowLEDnum);
    delay(Yellowontime);
    digitalWrite(YellowLEDpin,0);
    delay(Yellowofftime);
  }
    

  }
  
