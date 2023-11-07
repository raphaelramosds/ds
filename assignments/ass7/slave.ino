#include <avr/io.h>

void setup() {
  // Configure os pinos dos LEDs como saída
  DDRD |= (1 << DDD2) | (1 << DDD3) | (1 << DDD4);
  
  // Inicializa a comunicação serial no USART1
  UBRR1H = (unsigned char)(103 >> 8);
  UBRR1L = (unsigned char)103;
  UCSR1B = (1 << RXEN1) | (1 << TXEN1);
  UCSR1C = (1 << UCSZ11) | (1 << UCSZ10);
}

void loop() {
  if (UCSR1A & (1 << RXC1)) {
    char receivedData = UDR1;
    
    switch (receivedData) {
      case 'A':
        PORTD |= (1 << PD2); // Acende o LED no pino 2
        break;
      case 'B':
        PORTD |= (1 << PD3); // Acende o LED no pino 3
        break;
      case 'C':
        PORTD |= (1 << PD4); // Acende o LED no pino 4
        break;
      default:
        break;
    }
  }
}
