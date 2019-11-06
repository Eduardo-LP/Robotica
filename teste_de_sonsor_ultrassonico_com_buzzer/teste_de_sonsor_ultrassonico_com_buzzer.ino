#include <NewPing.h>

#define TRIGGER_PIN  8  // definição do pino trigger. 
#define ECHO_PIN     9  // definição do pino echo
#define MAX_DISTANCE 200 // configuração da variavel para a distancia maxima que o sensor ira medir

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // Definindo os parametros para a variavel sonar 

int buzzer = 2;
int distancia;

void setup() {
  Serial.begin(19200);
  pinMode(buzzer, OUTPUT);
  
}

void loop() {
  distancia = sonar.ping_cm();

if (distancia <= 9){
  Serial.println("aciona o buzzer");
  digitalWrite(buzzer, HIGH);
  }else{
    digitalWrite(buzzer,LOW);
    } 
}
