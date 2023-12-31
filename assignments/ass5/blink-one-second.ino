/**
 | --------------------------------------------------------
 | Lista 5
 | --------------------------------------------------------
 | Autores: Raphael Ramos
 |
 | µControlador: ATmega2560
 |
 | Consideração: o clock do ATmega2560 eh 16 MHz. Para 
 | fazer com que o tempo de estouro fosse 1s, precisei
 | de um registrador que contasse, pelo meno, ate 62500
 | por causa da seguinte equacao
 |
 | Testouro = (TOP + 1)(prescale)(Tosc)
 |
 | Entao, obtive TOP + 1 = 62500 para 
 | 
 | Testouro = 1s
 | prescale = 256
 | Tosc = 10^(-6)/16 s
 |
 | TCTN1 leva 1s para contar ate OCR1A = 62500
 |
 | Note: nao utilizei Timer0 pois nao eh possivel contar
 | ate 62500 com apenas 8 bits
*/

#include <avr/io.h>
#include <avr/interrupt.h>

int main() {
  // Habilitar interrupcoes
  sei();

  // Configurar pino de saida
  DDRB |= (1 << PB7);  

  // Configurar Timer1
  OCR1A = 0xF424; // TCNT1 leva 1s para contar ate 62500 = 0xF424
  TCCR1B |= (1 << WGM12); // Modo CTC
  TCCR1B |= (1 << CS12); // Prescale de 256
  TIMSK1 |= (1 << OCIE1A); // Compare MatchA

  while(1) {
    
  }
}

ISR(TIMER1_COMPA_vect) 
{
  PORTB ^= (1 << PB7);
}