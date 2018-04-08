//Transmitter
//visit www.rootsaid.com for full tutorial
//For Video Demo and tutorials Visit www.youtube.com/c/rootsaid


#include <SoftwareSerial.h>
#include<Servo.h>         

Servo esc; 
SoftwareSerial hc12(2, 3); //RX, TX

int thr, dir;

void setup()
{
esc.attach(10);
pinMode (A0, INPUT);
pinMode (A1, INPUT);

pinMode (13, OUTPUT);
 
Serial.begin(9600);
hc12.begin(9600);
}

void loop()
{
  ele=map(analogRead(A0), 0, 1023, 0, 180);
  dir=map(analogRead(A1), 0, 1023, 0, 180);
  
  hc12.print(thr);
  hc12.print(",");
  hc12.print(dir);
  hc12.println("");
 
  Serial.print(thr);
  Serial.print(",");
  Serial.print(dir);

  Serial.println("");


delay(100);  
}
