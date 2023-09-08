/**
 | --------------------------------------------------------
 | Projeto 1 - Semáforo
 | --------------------------------------------------------
 | Autores: Raphael Ramos
 |
 | µControlador: Atmega328p
 |
 | Descrição: Implementado com comandos em C, manipulando 
 | registradores. Usour-se três pinos consecutivos para 
 | tirar proveito do deslocamentos da cadeia de bits
*/

void setup()
{
  	// Utilizou-se os pinos PD5, PD6 e PD7 da porta D (8-bit)
  	// PD7 (green), PD6 (yellow) e PD5 (red) são de saída
  	DDRD = 0xE0; // 1110 0000 = 0xE0
}

void loop()
{ 
	// PD5 (red ON), PD6 (yellow OFF), PD7 (green OFF)
  	PORTD = 0X20; // 0010 0000
	delay(5000); // atraso de 5s
  
  	// PD5 (red OFF), PD6 (yellow ON), PD7 (green OFF)
  	PORTD <<= 1; // 0100 0000
  	delay(2000); // atraso de 2s
  
  	// PD5 (red OFF), PD6 (yellow OFF), PD7 (green ON)
  	PORTD <<= 1; // 1000 0000
  	delay(5000); // atraso de 5s
}