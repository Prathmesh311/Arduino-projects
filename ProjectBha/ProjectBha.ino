const int buzzerPin = 12;
const int flamePin = 11;
int Flame = HIGH;
int smokeA0 = A5;
int redled = 5;
int greenled = 6;
int sensorThres = 200; //Change this thresold value according to your sensitivity

void setup() {
  // put your setup code here, to run once:
   pinMode(buzzerPin, OUTPUT);
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(smokeA0,OUTPUT);

  pinMode(flamePin, INPUT);
  Serial.begin(9600);
  delay(100);

}


void loop() {
  // put your main code here, to run repeatedly:

  Flame = digitalRead(flamePin);
  if (Flame== LOW)
  {
    
      Serial.println("ATD9762517195;"); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
       Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     Serial.println("AT+CMGS=\"+919762517195\"\r"); // Replace x with mobile number
     Serial.println("🔥🔥FIRE IN THE HOUSE🔥🔥. Address Sukhwani Campus,Blue Bell-11,Flat no 301.");// The SMS text you want to send
     Serial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
     //delay(100);
     
    
  }
  else
  {

    digitalWrite(buzzerPin, LOW);
    digitalWrite(greenled, HIGH);
    digitalWrite(redled, LOW);
  }

  int analogSensor = analogRead(smokeA0);
  // Checks if it has reached the threshold value
  if (analogSensor > sensorThres)
  {
    digitalWrite(redled, HIGH);
    digitalWrite(greenled, LOW);
    
     Serial.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
     delay(1000);  // Delay of 1 second
     Serial.println("AT+CMGS=\"+919762517195\"\r"); // Replace x with mobile number
     Serial.println("""🔥🔥🔥🔥FIRE ALEART!🔥🔥🔥🔥  Sukhvani Complex,Blue bell 1,Valabhnagar.""" );// The SMS text you want to send
     Serial.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
     delay(100);
     digitalWrite(buzzerPin,HIGH);
     Serial.println("ATDxxxxxxxx;"); // ATDxxxxxxxxxx; semicolon should be at the last ;AT command that follows UART protocol;

  }
  else
  {
    digitalWrite(redled, LOW);
    digitalWrite(greenled, HIGH);
    //digitalWrite(buzzer,HIGH);
  }
  delay(50);




  }
