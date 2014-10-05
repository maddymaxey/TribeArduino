#include <avr/io.h>
#include <util/delay.h>



int tiltPin = 4;// Pin 3 ATtiny
int danceReading; 
//const int lightPin = 3; // photocell sensor // pin 2 ATtiny
int incomingSignal= HIGH;
const int lightPin = 3; // photocell sensor // pin 2 ATtiny
int lightLevel, high = 0, low = 1023; //defining the scope for lilght levels
const int LED_A = 0;
const int LED_B = 1;
const int LED_C = 2;


void setup()
{
  Serial.begin(9600);
   digitalWrite(tiltPin, HIGH); 
    pinMode(LED_A, OUTPUT);
    pinMode (LED_B, OUTPUT);
    pinMode (LED_C, OUTPUT);
    pinMode(lightPin, INPUT); 
    
}

void loop()
{
  
 single();
 checkingDance();

 

}

void checkingDance()//Authenricate Dance Signal with a 3 unit array
{
  //VARIABLES
  danceReading = digitalRead(tiltPin);
  
  //if loop testing for dance signal
  
  int danceCheckArray[10];
  int i=0;
  
  //Embedded while loop populating array
  
  while(i<11)
  {
    danceReading=digitalRead(tiltPin);
    danceCheckArray[i] = danceReading;
    i++;
    delay(100);
    
   
  }
  
  int total;
  total = danceCheckArray[0] + danceCheckArray[1] + danceCheckArray[2] +danceCheckArray[3] + danceCheckArray[4] + danceCheckArray[5] + danceCheckArray[6] +danceCheckArray[7] +danceCheckArray[8] + danceCheckArray[9] + danceCheckArray[10];
  //end of while loop
  
  if (total < 4)
  {
 
    
    checkingLight();


 }
 
 
 
  else if (total < 5)
  {
     int i = 0;
   while (i<10)
   { single2();
   i++;
   }
   
   reset_pins();

 }
 
 else
 {
     int i = 0;
   while (i<50)
   { lightparade();
   i++;
   }
   
   reset_pins();
 

}

}


void checkingLight()//Authenricate Light Signal with a 3 unit array
{
   
  lightLevel = analogRead(lightPin); 
   
   
  int lightCheckArray[5];
  int i=0;
  
  //Embedded while loop populating array
  
  while(i<6)
  {
         
     lightLevel = analogRead(lightPin); 
     
         if (lightLevel> 140 && lightLevel <250 ) // e cell phone screen at 47 ohms
{
      lightLevel=1 ;
     
      }
         else // neutral room at 47 ohms
     {
       
        lightLevel = 0;
     
      }
    
        lightCheckArray[i] = lightLevel;

    i++;
    delay(100);  
   
  }
  
  int total;
  total = lightCheckArray[0] + lightCheckArray[1] + lightCheckArray[2] +lightCheckArray[3]+lightCheckArray[4]+lightCheckArray[5];
     
     if (total > 5)
     
{
      int i = 0;
   while (i<50)
   { crazy();
   i++;
   }
   reset_pins();
  
} 





}
  
  
  void reset_pins()
{
  // start by ensuring all pins are at input and low
  digitalWrite(LED_A, LOW); 
   digitalWrite(LED_B, LOW); 
    digitalWrite(LED_C, LOW); 
}



  void blinking1()
{

  // in turn and holding for half a second. // LED 4 & 5
   digitalWrite(LED_A, HIGH); 
   digitalWrite(LED_B, HIGH); 
    digitalWrite(LED_C, HIGH); 
  delay(800);
      digitalWrite(LED_A, LOW); 
   digitalWrite(LED_B, LOW); 
    digitalWrite(LED_C, LOW); 
  delay(100);

}

  void blinking2()
{
   digitalWrite(LED_A, HIGH); 
   digitalWrite(LED_B, LOW); 
    digitalWrite(LED_C, HIGH); 
  delay(200);
      digitalWrite(LED_A, LOW); 
   digitalWrite(LED_B, HIGH); 
    digitalWrite(LED_C, LOW); 
  delay(200);

}

  void crazy()
{

 
    digitalWrite(LED_C, HIGH); 
  delay(400);
 digitalWrite(LED_A, HIGH); 
  delay(400);
   digitalWrite(LED_B, HIGH); 
  delay(400);
  digitalWrite(LED_C, LOW); 
  delay(400);
 digitalWrite(LED_A, LOW); 
  delay(400);
   digitalWrite(LED_C, HIGH); 
  delay(400);
   digitalWrite(LED_A, HIGH); 
  delay(400);


}


void single()
{
  
   digitalWrite(LED_A, HIGH); 


}

void single2()
{
  
   digitalWrite(LED_A, HIGH);
   delay(100);
    digitalWrite(LED_B, HIGH);  
    delay(600);
     digitalWrite(LED_A, LOW);
   delay(100);
   digitalWrite(LED_B, LOW);  
    delay(100);


}



 void lightparade()
{
  // run through a sample loop, lighting each LED

  // in turn and holding for half a second.
  digitalWrite(LED_A, HIGH);
   delay(100);
digitalWrite(LED_A, LOW);
   delay(100);
  digitalWrite(LED_B, HIGH);
   delay(1000);
digitalWrite(LED_B, LOW);
   delay(100);
  digitalWrite(LED_C, HIGH);
   delay(100);
     
}

