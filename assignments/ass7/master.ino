// ========================================================================
// Lista 7
// ========================================================================
// Autor: Raphael Ramos
// µControlador: ATmega2560
// ========================================================================

#include <avr/io.h>
#include <util/delay.h>

void usart0_init(unsigned int ubrr) {
  // Configura a taxa de transmissão
  UBRR0H = (unsigned char)(ubrr >> 8);
  UBRR0L = (unsigned char)ubrr;
  // Ativa o transmissor e receptor
  UCSR0B = (1 << TXEN0) | (1 << RXEN0);
  // Define o formato dos dados: 8 bits de dados, 1 bit de parada
  UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

void usart1_init(unsigned int ubrr) {
  // Configura a taxa de transmissão
  UBRR1H = (unsigned char)(ubrr >> 8);
  UBRR1L = (unsigned char)ubrr;
  // Ativa o transmissor e receptor
  UCSR1B = (1 << TXEN1) | (1 << RXEN1);
  // Define o formato dos dados: 8 bits de dados, 1 bit de parada
  UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);
}

void usart0_transmit(unsigned char data) {
  // Aguarda até que o buffer de transmissão esteja vazio
  while (!(UCSR0A & (1 << UDRE0)));
  // Coloca os dados no buffer de transmissão
  UDR0 = data;
}

void usart1_transmit(unsigned char data) {
  // Aguarda até que o buffer de transmissão esteja vazio
  while (!(UCSR1A & (1 << UDRE1)));
  // Coloca os dados no buffer de transmissão
  UDR1 = data;
}

int main(void) {
  // Inicializa o USART0 e USART1
  usart0_init(9600);
  usart1_init(9600);

  while (1) {
    // Envie as mensagens pelo USART1
    usart1_transmit('A');
    _delay_ms(1000);
    usart1_transmit('B');
    _delay_ms(1000);
    usart1_transmit('C');
    _delay_ms(1000);
  }
}
