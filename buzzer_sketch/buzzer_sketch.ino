
int detectpin=8;
int sensorpin=A0;
int buzzerpin=9;
int count=0;
void setup()
{
  pinMode(detectpin,OUTPUT);
  pinMode(sensorpin,INPUT);
  pinMode(buzzerpin,OUTPUT);
  digitalWrite(detectpin,HIGH);
  Serial.begin(9600);


}
void loop()
{
  int value=digitalRead(sensorpin);
  //Serial.println(value);
 Serial.println(count);
  
  if(value==1)
  {
    //buzz(1000);
    count++; 
    delay(2000);
    
  }
    
  
 
  if(count==3)
  {
    //Serial.println("AT");
  Serial.println("AT+CMGF=1");
  delay(1000);
Serial.println("AT+CMGS=\"+918800833480\"");
delay(1000);
//while(!Serial.find(">"));
//{
Serial.println("message");
delay(100);
Serial.write(0X1A);
delay(1000);
Serial.println();
//}
  count=0;
  }
  
  
  
}


void buzz(int time)
  {
    digitalWrite(buzzerpin,1);
    delay(time);
    digitalWrite(buzzerpin,0);
    delay(time);
  }
