#include <Servo.h>
// definir as "variaveis' para cada servo
Servo servoDireito;
Servo servoEsquerdo;

int vel = 0;

int b1 = 7;
int b2 = 8;


int estadob1;
int estadob2;


void setup() {
pinMode(b1, INPUT);
pinMode(b2, INPUT);


servoDireito.attach(2);
servoEsquerdo.attach(3);

}

void loop() {
  estadob1 = digitalRead(b1);
  estadob2 = digitalRead(b2);
  
   vel = 200;
    
 if (estadob1 == HIGH){
    
     servoDireito.writeMicroseconds(1500 + vel);
     servoEsquerdo.writeMicroseconds(1500 - vel);
     
    }
 if(estadob2 == HIGH){
      
      servoDireito.writeMicroseconds(1500 - vel);
      servoEsquerdo.writeMicroseconds(1500 + vel);
      
      }
 if(estadob1 == HIGH && estadob2 == HIGH){
  
      servoDireito.writeMicroseconds(1700);
      servoEsquerdo.writeMicroseconds(1700);

  }


}
