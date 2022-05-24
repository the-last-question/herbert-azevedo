//Arduino 1
/*sensor ultrasônico e led*/
  
#define echoPin 11 //pino que recebe o pulso echo
#define trigPin 10 //pino que envia o pulso para gerar o echo
#include <SoftwareSerial.h>
#include <string.h>


int led = 12;
int led2 = 7;
int led3 = 4;


float duracao = 0;
float distancia = 0;
  
SoftwareSerial serial(0,1); //(rx, tx)


void setup()
{
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  serial.begin(9600);
}


void loop()
{
  digitalWrite(trigPin, HIGH); //eleva o sinal do Trigger
  delayMicroseconds(10);       //por 10 microsegundos
  digitalWrite(trigPin, LOW);
  
  //armazena o valor de microsegundos que foi lido
  duracao = pulseIn(echoPin, HIGH);
   
  distancia = duracao * 0.017; // ((340 * 100) / 10e6)
  /*sobre a formula
  - velocidade do som no ar 340 m/s
  - multiplique-o por 100 para transformar em centímetros
  - dividi-o por 1.000.000 como a duracao esta medida em microsegundos
  - divide-o por 2 como o sinal de ultrasom viaja ate o objeto e depois 
  faz o mesmo caminho de retorno
  - o resultado é 0.017
  */
  
  if(distancia <= 110){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
  }
  if (distancia > 111 & distancia < 222){
   	digitalWrite(led2, HIGH);
    delay(1000);
    digitalWrite(led2, LOW);
  }
  if (distancia > 222){
   	digitalWrite(led3, HIGH);
    delay(1000);
    digitalWrite(led3, LOW);
  }
  
  String stringOne = String(distancia, 5);
  
  Serial.print("distancia:");
  Serial.print(distancia);
  Serial.println("cm");
  delay(2000);
    
}
