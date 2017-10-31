//int out=8;
#include <Servo.h>

Servo myservo;
int pos=0;
int led=12;
int buzzpin=9;
int count=0;
char junk;
String inputString="";

//int ir=0;
int x;
void setup()
{
  
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(12,OUTPUT);
  pinMode(buzzpin,OUTPUT);
  pinMode(2, OUTPUT);
 pinMode(4,OUTPUT);
//pinMode(out,INPUT);
//pinMode(led,OUTPUT);
}
void loop()
{
 x=digitalRead(7);
//Serial.println(x);
if (x==1)
 {
digitalWrite(12,HIGH);
count++;
delay(1000);
Serial.println(count);
}
if (x==1 && count==2)
{
digitalWrite(12,LOW);
count=0;
}
if(Serial.available())
{
ir();  
 

}
}
void ir()
{
while(Serial.available())
    {
      char inChar = (char)Serial.read(); //read the input
      inputString += inChar;        //make a string of the characters coming on serial
    }
    Serial.println(inputString);
    while (Serial.available() > 0)  
    { 
    junk = Serial.read() ;
  }      // clear the serial buffer
    if(inputString == "a")
    {         //in case of 'a' turn the LED on
      digitalWrite(2, HIGH);  
    }
    else if(inputString == "b")
    {   //incase of 'b' turn the LED off
      digitalWrite(2, LOW);
    }
   if(inputString == "c")
   {         //in case of 'a' turn the LED on
      digitalWrite(4, HIGH);  
    }
    else if(inputString == "d")
    {   //incase of 'b' turn the LED off
      digitalWrite(4, LOW);
   }
   if (inputString=="e")
   {
   for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
     }
  else if (inputString=="f")
  {
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(20); 
    
  //for(pos = pos; pos < 3; pos += 1)  // goes from 0 degrees to 180 degrees 
  //{                                  // in steps of 1 degree 
   //myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    //delay(15);                       // waits 15ms for the servo to reach the position 
  //} 
  }
  } 
  
   
    inputString = "";
  }
 






/*void intruder(unsigned char time)
{
analogWrite(buzzpin,170);
delay(time);
analogWrite(buzzpin,0);
delay(time);
}


  //ir=Serial.read(out);
 //if (Serial.available())
  //{
  //Serial.print (ir);
  //}
*/

