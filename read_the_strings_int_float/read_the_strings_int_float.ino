String myname;                   //string variable declare for name
int age;                         //int variable declare for age
float height;                    //float variable dcalre for height  



void setup() 
{
      // put your setup code here, to run once:
      Serial.begin(96000);
}

void loop() 
{
      // put your main code here, to run repeatedly:

      Serial.println("enter your name");
      while(Serial.available()==0)
      {
        
      }
      myname=Serial.readString();

      Serial.println("How old are you?");
      while(Serial.available()==0)
      {
        
      }
      age=Serial.parseInt();

      Serial.println("How much do you height?");
      while(Serial.available()==0)
      {
        
      }
      height=Serial.parseFloat();
      Serial.println("");

      Serial.print("hello ");
      Serial.print(myname);
      Serial.println("you are ");
      Serial.print(age);
      Serial.print(" years old");
      Serial.println("and your height is ");
      Serial.print(height);
      
      
}
