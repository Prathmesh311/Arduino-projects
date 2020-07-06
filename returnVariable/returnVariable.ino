void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  float x;
  float x2;

  Serial.println("Enterthe number you want to be squared ");
  while(Serial.available()==0)
  {
    
  }
  x=Serial.parseFloat();
  x2=x_square(x);
  Serial.println("Square is " );
  Serial.println(x2);

}

float x_square(float x)
{
  float answer;
  answer=x*x;
  return answer;
}
