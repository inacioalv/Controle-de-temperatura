// Biblioteca LCD
#include <LiquidCrystal.h>


const int buzzer = 9; //fix to pin no. 9

// Inicializa a biblioteca LCD
LiquidCrystal LCD(12,11,5,4,3,2);

// Define o pino analogico A0 como entrada do Sensor de Temperatura
int SensorTempPino=0;

// Define o pino 8 para o alerta de temperatura baixa
int AlertaTempBaixa=8;
// Define o pino 13 para o alerta de temperatura alta
int AlertaTempAlta=13;

// Define temperatura baixa como abaixo de zero grau Celsius
int TempBaixa=0;
// Define temperatura alta como acima de 40 graus Celsius
int TempAlta=40;

void setup() {
    // Set buzzer - pin 9 as an output
  	pinMode(buzzer, OUTPUT); 
  	
    //Define a porta do led como saida
    pinMode(10, OUTPUT);
  
  	//Define a porta do motor como saida
    pinMode(13, OUTPUT);
  
	// Define a quantidade de colunas e linhas do LCD
	LCD.begin(16,2);
	// Imprime a mensagem no LCD
	LCD.print("Temperatura:");
	// Muda o cursor para a primeira coluna e segunda linha do LCD
	LCD.setCursor(0,1);
	// Imprime a mensagem no LCD
	LCD.print("      C     ");
}

void loop() {
  
	// Faz a leitura da tensao no Sensor de Temperatura
	int SensorTempTensao=analogRead(SensorTempPino);

  	// Converte a tensao lida
	float Tensao=SensorTempTensao*5;
	Tensao/=1024;

  	// Converte a tensao lida em Graus Celsius
	float TemperaturaC=((Tensao-0.5)*100)+30;

  	// Muda o cursor para a primeira coluna e segunda linha do LCD
  	LCD.setCursor(0,1);

  	// Imprime a temperatura em Graus Celsius
	LCD.print(TemperaturaC);
  
  
  	if(TemperaturaC >50){  
    	tone(buzzer, 400, 50);
      	//Acende o led
   		digitalWrite(10, HIGH);
        //Aguarda intervalo de tempo em milissegundos
        delay(500);
        //Apaga o led
        digitalWrite(10, LOW);
        //Aguarda intervalo de tempo em milissegundos
        delay(500);
    }
  
  	if(TemperaturaC >=30){  
    	digitalWrite(13, HIGH);
    }

  	// Aguarda 1 segundo
  	delay(1000);
}