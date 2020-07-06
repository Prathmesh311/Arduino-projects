int Redpin=9;
int Yellowpin=10;
int numRedblinkes;
int numYellowblinkes;
int Redontime;
int Redofftime;
int Yellowontime;
int Yellowofftime;
String Redmassage= "Red LED is blinking ";
String Yellowmassage="Yellow LED is blinking";



void setup() {

    Serial.begin(96000);
    pinMode(Redpin,OUTPUT);
    pinMode(Yellowpin, OUTPUT);



    //Number of times Leds blinke are ask to user 
    
    Serial.print("Enter the number of times Red LED blinkes");
    while (Serial.available()==0 ){}
    numRedblinkes=Serial.parseInt();
    

    Serial.print("Enter the number of times Yellow LED blinkes");
    while (Serial.available()==0 ){}
    numYellowblinkes=Serial.parseInt();

    //Time span for LED on is ask to user
    
    Serial.print("Enter the time Yellow LED On");
    while (Serial.available()==0 ){}
    Yellowontime= Serial.parseInt();



    Serial.print("Enter for time Red LED on");
    while (Serial.available()==0 ){}
    Redontime=Serial.parseInt();


    //Time span of LEDs to off is ask to users

    Serial.print("Time for Red LED should off");
    while (Serial.available()==0 ){}
    Redofftime=Serial.parseInt();



    Serial.print("Enter time Yellow LED off  time");
    while(Serial.available( )==0 ) {}
    Yellowofftime=Serial.parseInt();
   
  
}
void loop() {
  
  Serial.print(Redmassage);
  for (int j=0;j-1<numRedblinkes;j++){
    Serial.print("Red lED is blinkes");
    Serial.println(j);
    digitalWrite(Redpin,HIGH);
    delay(Redontime);
    digitalWrite(Redpin,LOW);
    delay(Redofftime);
  }


  Serial.print(Yellowmassage);
  for ( int j=0;j-1<numYellowblinkes;j++){
    Serial.print("Yellow LED is blinkes");
    Serial.println(j);
    digitalWrite(Yellowpin,HIGH);
    delay(Yellowontime);
    digitalWrite(Yellowpin,LOW);
    delay(Yellowofftime);
    
  }

}
