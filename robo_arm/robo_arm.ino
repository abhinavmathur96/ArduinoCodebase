// code controls an arduino based robot arm 
// used 4 servo motors

#include <Servo.h>

Servo myservo3;
Servo myservo5;
Servo myservo6;
Servo myservo9;
Servo myservo11;

int potpin = 1;
int potpin2 = 2;
int potpin3 = 3;
int potpin4 = 4;
int potpin5 = 5;

int val = 0;
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;

void setup()
{
myservo3.attach(3);
myservo5.attach(5);
myservo6.attach(6);
myservo9.attach(9);
myservo11.attach(11);
}

void loop()
{

val = analogRead(potpin);
val = map(val, 0, 1023, 0, 179);
myservo3.write(val);
delay(5);
val2 = analogRead(potpin2);
val2 = map(val2, 0, 1023, 0, 179);
myservo5.write(val2);
delay(5);
val3 = analogRead(potpin3);
val3 = map(val3, 0, 1023, 0, 179);
myservo6.write(val3);
delay(5);
val4 = analogRead(potpin4);
val4 = map(val4, 0, 1023, 0, 179);
myservo9.write(val4);
delay(5);
val5 = analogRead(potpin5);
val5 = map(val5, 0, 1023, 0, 179);
myservo11.write(val5);
delay(5);
}
                                                    
