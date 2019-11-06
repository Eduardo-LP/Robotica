/*
  Teste do Sensor IR
*/

int sensorIrDirPin = A0;
int sensorIrEsqPin = A1;
int ledPin = 13;      // selecionar o pino do LED

//Faixas de valores usadas para identificação das cores
const int COR_CINZA_MIN = 150;
const int COR_BRANCA_MIN = 150;
const int COR_BRANCA_MAX = 500;
const int COR_VERDE_MIN = 500;
const int COR_VERDE_MAX = 850;
const int COR_PRETA_MAX = 850;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
  // declare the ledPin as an OUTPUT:
  pinMode(ledPin, OUTPUT);
}

// Função que faz a leitura do valor do sensor IR conectado à uma 
// entrada analógica e retorna a cor detectada pelo sensor
//    * sensorPino  :   pino de entrada analógica
//    * sensorIrCor :   valor de cor detectada (0=nenhuma; 1=preto; 2=branco; 3=verde; 4=cinza)  
//
int sensorIrDetectaCor(int sensorPino){
  
  int sensorIrValor=0; // variavel local para gravar valor da leitura do sensor IR
  int sensorIrCor=0; // variavel local para gravar cor lida pelo sensor
  
  // Faz a leitura do sensor IR
  sensorIrValor = analogRead(sensorPino);
  Serial.print("Valor da Entrada analógica: ");
  Serial.print(sensorIrValor);

  // testa dentro das faixas de valores  
  if (sensorIrValor > COR_PRETA_MAX) {
    sensorIrCor = 1;
    Serial.println(" - cor PRETA");
  } else if (sensorIrValor < COR_CINZA_MIN) {
    sensorIrCor = 2;
    Serial.println(" - cor CINZA");
  } else if (sensorIrValor > COR_VERDE_MIN && sensorIrValor < COR_VERDE_MAX) {
    sensorIrCor = 3;
    Serial.println(" - cor VERDE");
  } else if (sensorIrValor > COR_BRANCA_MIN && sensorIrValor < COR_BRANCA_MAX) {
    sensorIrCor = 4;
    Serial.println(" - cor BRANCA");
  } else {
    sensorIrCor = 0;
    Serial.println(" - não detectado");
  }  
  // retorna valor de cor
  return sensorIrCor;
}

void loop() {
  int sensorIrDirCor = 0; // variavel local com a cor detectada no sensor IR direito
  int sensorIrEsqCor = 0; // variavel local com a cor detectada no sensor IR esquerdo
  
  // turn the ledPin on
  digitalWrite(ledPin, HIGH);
  Serial.println("-- IR Teste --");

  // chama função para detectar a cor do sensor IR Direito
  Serial.println("Leitura do Sensor IR Direito");
  sensorIrDirCor = sensorIrDetectaCor(sensorIrDirPin);

  // chama função para detectar a cor do sensor IR Esquerdo
  Serial.println("Leitura do Sensor IR Esquerdo");
  sensorIrEsqCor = sensorIrDetectaCor(sensorIrEsqPin);
  
  // stop the program for 1000 milliseconds:
  delay(1000);
  // turn the ledPin off:
  digitalWrite(ledPin, LOW);
  // stop the program for 1000 milliseconds:
  delay(1000);
}
