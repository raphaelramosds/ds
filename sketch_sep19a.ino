#include <avr/io.h>
#include <avr/interrupt.h>

/*
* Utilizar um temporizador TC0
* no modo normal para piscar no tempo 
* de estouro de TC0
*/

int main(void) {
  sei();
  
  // Configura os pinos de entrada e saída
  DDRB |= (1 << PB7);

  // Normal port operation
  TCCR0A = 0x0;

  // TCCR0B |= (1 << CS00);
  TCCR0B = 0x1;

  // TIMSK0 |= (1 << TOIE0);
  TIMSK0 = 0x1;

  // Configura o comparador

  while(1) {
    // Programa principal

  }
}

ISR(TIMER0_OVF_vect)
{
  PORTB ^= (1 << PB7);
}