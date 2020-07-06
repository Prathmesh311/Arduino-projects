int redpin=11;
int greenpin=10;
int bluepin=6;

int s2=7;
int s3=8;
int outpin=4;

int rcolourstrength;
int bcolourstrength;
int gcolourstrength;

unsigned int pulseWidth;

 
void setup() 
{
       // put your setup code here, to run once:

       Serial.begin(9600);
       pinMode(redpin,OUTPUT);
       pinMode(greenpin, OUTPUT);
       pinMode(bluepin,OUTPUT);

       pinMode(s2, OUTPUT);
       pinMode(s3, OUTPUT);
       pinMode(outpin, INPUT);
       
}

void loop() 
{
       // lets start reading  red component if colour
       //  s2 and s3 set to low
       digitalWrite(s2, LOW);
       digitalWrite(s3, LOW);

       pulseWidth = pulseIn(outpin, LOW);

       rcolourstrength=pulseWidth/400.-1;
       rcolourstrength=(255-rcolourstrength);


        // lets start reading  green component if colour
       //  s2 and s3 set to high
       digitalWrite(s2, HIGH);
       digitalWrite(s3, HIGH);

       pulseWidth = pulseIn(outpin, LOW);

       gcolourstrength=pulseWidth/400.-1;
       gcolourstrength=(255-gcolourstrength);

        // lets start reading  blue component if colour
       //  s2 and s3 set to low and high respectively
       digitalWrite(s2, LOW);
       digitalWrite(s3, HIGH);

       pulseWidth = pulseIn(outpin, LOW);

       bcolourstrength=pulseWidth/400.-1;
       bcolourstrength=(255-bcolourstrength);

       Serial.print(rcolourstrength);
       Serial.print(",");
       Serial.print(gcolourstrength);
       Serial.print(",");
       Serial.print(bcolourstrength);
       Serial.println("");

       if(rcolourstrength>bcolourstrength && gcolourstrength>bcolourstrength)
       {
          rcolourstrength = 255;
          gcolourstrength=gcolourstrength/2;
          bcolourstrength=0;
       }

              if(rcolourstrength>bcolourstrength && bcolourstrength>gcolourstrength)
       {
          rcolourstrength = 255;
          bcolourstrength=bcolourstrength/2;
          gcolourstrength=0;
       }

              if(bcolourstrength>rcolourstrength && rcolourstrength>gcolourstrength)
       {
          bcolourstrength = 255;
          rcolourstrength=rcolourstrength/2;
          gcolourstrength=0;
       }

              if(bcolourstrength>gcolourstrength && gcolourstrength>rcolourstrength)
       {
          bcolourstrength = 255;
          gcolourstrength=gcolourstrength/2;
          rcolourstrength=0;
       }

              if(gcolourstrength>bcolourstrength && bcolourstrength>rcolourstrength)
       {
          gcolourstrength = 255;
          bcolourstrength=bcolourstrength/2;
          rcolourstrength=0;
       }

              if(gcolourstrength>rcolourstrength && rcolourstrength>bcolourstrength)
       {
          gcolourstrength = 255;
          rcolourstrength=rcolourstrength/2;
          bcolourstrength=0;
       }

              if(rcolourstrength>bcolourstrength && rcolourstrength>gcolourstrength)
       {
          rcolourstrength = 255;
          gcolourstrength=gcolourstrength/2;
          bcolourstrength=0;
       }

              if(rcolourstrength>bcolourstrength && rcolourstrength>gcolourstrength)
       {
          rcolourstrength = 255;
          gcolourstrength=gcolourstrength/2;
          bcolourstrength=0;
       }

       
}
