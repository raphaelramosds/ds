/**
 | --------------------------------------------------------
 | Lab 1
 | --------------------------------------------------------
 | Autores: Raphael Ramos
 |
 | µControlador: Atmega2560
 |
 | Descrição: Impulso implementado com comandos em C 
 | manipulando  registradores.
*/

void setup()
{
  DDRH = 0x20; 
}

void loop()
{
  PORTH = 0x20;
  PORTH = 0x0;
  delay(5);
}