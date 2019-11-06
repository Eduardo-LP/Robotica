#include <Servo.h>

Servo servoDireita;
Servo servoEsquerda;
int vel = 0;
void setup()
{

  
  servoDireita.attach(2);
  servoEsquerda.attach(3);

  vel = 50;
  servoDireita.writeMicroseconds(1500 + vel);
  servoEsquerda.writeMicroseconds(1500 - vel);
  delay(10000);
 

 
}


void loop()
{

}

