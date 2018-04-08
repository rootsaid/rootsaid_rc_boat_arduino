//Receiver
//Visit www.rootsaid.com for full tutorial
//For Video Demo and tutorials Visit www.youtube.com/c/rootsaid

#include <SoftwareSerial.h>
#include<Servo.h>          

Servo ele;

String input;

int throttle, th;
int direction, dir;


int boundLow;
int boundHigh;
const char delimiter = ',';

SoftwareSerial hc12(4, 5);

void setup()
{

pinMode (4, OUTPUT); //enable
pinMode (6, OUTPUT);
pinMode (7, OUTPUT);

dir.attach(9);
Serial.begin(9600);
hc12.begin(9600);
digitalWrite(4, HIGH);
}

void loop()
{

if(Serial.available())
  {
  input = Serial.readStringUntil('\n');
  if (input.length() > 0)
      {
       // Serial.println(input);
       
        boundLow = input.indexOf(delimiter);
        throttle = input.substring(0, boundLow).toInt();
   
        dir = input.substring(boundLow+1).toInt();
      
        if (throttle >= 60)
          {
            forward();
            dir.write(direction);
            delay(10); 
          }
          
        else if (throttle <= 30)
          {
            backward();
            dir.write(direction);
            delay(10); 
          }
          
           else
          {
            stop();
            dir.write(direction);
            delay(10);      
          }
      }

  }

}
void forward()
{
digitalWrite(6, HIGH);
digitalWrite(7, LOW);
}
void bacward()
{
digitalWrite(6, LOW);
digitalWrite(7, HIGH);
}
void stop()
{
digitalWrite(6, LOW);
digitalWrite(7, LOW);
}
