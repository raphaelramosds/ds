/**
 | --------------------------------------------------------
 | Lab 1
 | --------------------------------------------------------
 | Autores: Raphael Ramos
 |
 | µControlador: Atmega2560
 |
 | Descrição: Impulso implementado com comandos
 | nativos do arduino UNO
*/

void setup()
{
  pinMode(8, OUTPUT);
}

void loop()
{
  digitalWrite(8, HIGH);
  digitalWrite(8, LOW);
  delay(5);
}