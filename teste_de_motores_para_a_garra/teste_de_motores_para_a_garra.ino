//configuração da entrada do motor A
int Ab1 = A2;
int Aa1 = A3;

void setup() {
 
  pinMode(Ab1, OUTPUT);
  pinMode(Aa1, OUTPUT);
 
}

void loop() {
// programação ultilizando blocos de void
  direcao(1);
  delay (5000);

  parado();
  delay(2000);

  direcao(3);
  delay (5000);

  parado();
  delay(2000);

}

void direcao(int comando){
  /* o void direção é usado para controlar o sentido do motor, no caso um motor dc
  que eu utilizarei para controla a garra*/
 
   int inPin1 = 220;
   int inPin2 = 0;

   if (comando == 1){
    inPin1 = 0;
    inPin2 = 220;
    
    }

    analogWrite(Ab1, inPin1);
    analogWrite (Aa1, inPin2);
  
  }

  void parado(){
    analogWrite(Ab1, LOW);
    analogWrite(Aa1, LOW);
    
    }
