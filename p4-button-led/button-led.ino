/**
 | --------------------------------------------------------
 | Lista 2
 | --------------------------------------------------------
 | Autores: Raphael Ramos
 |
 | µControlador: Atmega328p
 |
 | Descrição: Implementado com comandos em C, manipulando 
 | registradores. 
 |
 | Consideração: Podemos ler/escrever nos pinos da porta x
 | manipulando o regitrador DDRx da porta x com
 | - PINx, equivalente ao digitalRead, para ler os pinos
 | - PORTx, equivalente ao digitalWrite, para escrver nos pinos
*/

void setup()
{
  // PB1 entrada (0) e PB5 saida (1)
  // 0010 0000 = 0x20
  DDRB = 0x20;
}

void loop()
{
	// Se PB1 tiver alto, o botão foi pressionado
  	if ((PINB >> PB1) & 0x01) {
      	// PB5 liga (bit = 1)
      	PORTB |= (1 << PB5);
    } 
	
	// Se PB1 tiver baixo, o botão não foi pressionado
	else {
      	// PB5 desliga (bit = 0)
      	PORTB &= ~(1 << PB5);
    }
}