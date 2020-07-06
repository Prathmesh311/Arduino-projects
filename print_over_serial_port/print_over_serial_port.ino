int RedLED=9;
int BlueLED=13;
int RedLEDon=900;
int RedLEDoff=100;
int BlueLEDon=900;
int BlueLEDoff=100;
int numRedBlinkes=5;
int numBlueBlinkes=5;


void setup() {
  Serial.print(9600);
  pinMode(RedLED,OUTPUT);
  pinMode(BlueLED,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
  Serial.print("Number of times Red LED blinkes");
  for(int j=1;j<=numRedBlinkes;j=j+1) { 
  
     Serial.print(j);
     digitalWrite(RedLED,HIGH); 
     delay(RedLEDon);
     digitalWrite(RedLED3,LOW);
     delay(RedLEDoff);
  }
  Serial.print("Number of times Blue LED blinkes ");
  for(int j=0;j<=numBlueBlinkes;j=j+1) 
    Serial.print(j); 
    digitalWrite(BlueLED,HIGH);
    delay(BlueLEDon);
    digitalWrite(BlueLED,LOW);
    delay(BlueLEDoff);
    
  }
  // put your main code here, to run repeatedly:

}
