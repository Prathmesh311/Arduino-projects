#include<LiquidCrystal.h>  //load liquid crystal liabrary
LiquidCrystal LCD(10,9,5,4,3,2);
int myCounter;


void setup() {
  // put your setup code here, to run once:
  LCD.begin(16,2);
  LCD.setCursor(0,0);
  LCD.print("My timer");
  
  
}

void loop() {
  // put your main code here, to run repeatedly:

  for(myCounter=1;myCounter<=10;myCounter=myCounter+1)
  {
    LCD.setCursor(0,1);
    LCD.print("                ");

    LCD.print(myCounter);
    LCD.print(" sencond");
    delay(1000);
  }

  for (myCounter=10;myCounter>=0;myCounter=myCounter-1)
  {
    LCD.setCursor(0,1);
    LCD.print("                ");

    LCD.print(myCounter);
    LCD.print(" seconds");
    delay(1000);
  }
}
