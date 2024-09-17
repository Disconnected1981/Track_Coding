// C++ code
//
#include<Servo.h>

int rot = 7;
int gelb = 6;
int gruen = 5;

Servo Schranke;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(rot, OUTPUT);
  pinMode(gelb, OUTPUT);
  pinMode(gruen, OUTPUT);
  
  Schranke.attach(10);
}

void SchrankeSchliessen() {
  Schranke.write(0);
}

void SchrankeOeffnen() {
  Schranke.write(90);
}

void SchalteAmpel(int ampelFarbe) {
  digitalWrite(rot, ampelFarbe == 7 ? HIGH : LOW);
  digitalWrite(gelb, ampelFarbe == 6 ? HIGH : LOW);
  digitalWrite(gruen, ampelFarbe == 5 ? HIGH : LOW); 
}

void loop()
{
  SchrankeSchliessen();
  SchalteAmpel(rot);
  delay(5000); // Wait for 1000 millisecond(s)
  SchalteAmpel(gelb);
  delay(1000); // Wait for 1000 millisecond(s)
  SchalteAmpel(gruen);
  SchrankeOeffnen();
  delay(5000); // Wait for 1000 millisecond(s)
  SchalteAmpel(gelb);
  delay(1000); // Wait for 1000 millisecond(s)
}