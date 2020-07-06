float grades[25];
int numgrades;
float avg;
int i;
float sumgrades=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  InputGrades();
  avgGrades();
  DisplayGrades();
}

void InputGrades()
{
   Serial.println("enter the number of gragdes");
  while(Serial.available()==0)
  {
    
  }
  numgrades=Serial.parseInt();

  for(i=0;i<numgrades;i++)
  {
    Serial.println("Enter the Grades");
    while(Serial.available()==0)
    {
      
    }
    grades[i]=Serial.parseFloat();
}

void avgGrades()
{
  for(i=0;i<numgrades;i++)
  {
    sumgrades=sumgrades+grades[i];
  }

  avg=sumgrades/numgrades;
  sumgrades=0;
}

void DisplayGrades()
{
   Serial.println("your average is:");
  Serial.println(avg);
  Serial.println("");  
  
}
