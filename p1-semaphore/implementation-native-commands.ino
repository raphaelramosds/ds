/**
 | --------------------------------------------------------
 | Projeto 1 - Semáforo
 | --------------------------------------------------------
 | Autores: Raphael Ramos
 |
 | µControlador: Atmega328p
 |
 | Descrição: Implementado com comandos nativos do arduino UNO
*/

void setup() 
{
    pinMode(PD7, OUTPUT);
    pinMode(PD6, OUTPUT);
    pinMode(PD5, OUTPUT);
}

void loop() 
{
    // PD5 (red ON), PD6 (yellow OFF), PD7 (green OFF)
    digitalWrite(PD7, LOW);
    digitalWrite(PD6, LOW);
    digitalWrite(PD5, HIGH);
    delay(5000);

  	// PD5 (red OFF), PD6 (yellow ON), PD7 (green OFF)
    digitalWrite(PD7, LOW);
    digitalWrite(PD6, HIGH);
    digitalWrite(PD5, LOW);
    delay(2000);

  	// PD5 (red OFF), PD6 (yellow OFF), PD7 (green ON)
    digitalWrite(PD7, HIGH);
    digitalWrite(PD6, LOW);
    digitalWrite(PD5, LOW);
    delay(5000);
}