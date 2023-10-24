#include <Servo.h>

Servo myservo,myservo1,myservo2;  

int pos = 0;    

void setup() {
  myservo.attach(D1);
  myservo1.attach(D2);
  myservo2.attach(D3);
  myservo.write(pos);
  myservo1.write(pos);
  myservo2.write(pos);
  delay(2000);
}

void loop() {
for(pos = 0;pos<=180;pos+=1)
{
  myservo.write(pos);
  delay(20);
}
delay(100);
for(pos = 0;pos<=180;pos+=1)
{
  myservo1.write(pos);
  delay(20);
}
delay(100);
for(pos = 0;pos<=180;pos+=1)
{
  myservo2.write(pos);
  delay(20);
}
delay(100);
for(pos = 180;pos>=0;pos-=1)
{
  myservo.write(pos);
  delay(20);
}
delay(100);
for(pos = 180;pos>=0;pos-=1)
{
  myservo1.write(pos);
  delay(20);
}
delay(100);
for(pos = 180;pos>=0;pos-=1)
{
  myservo2.write(pos);
  delay(20);
}
delay(100);
}
