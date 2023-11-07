#include <avr/io.h>

void spi_init() {
  // Configurar o escravo
  // Configurar MISO como saída
  DDRB = (1 << DDB4);
  
  // Habilitar SPI
  SPCR = (1 << SPE);
}

char spi_receive() {
  // Aguardar a recepção de dados
  while (!(SPSR & (1 << SPIF)));
  
  // Retornar os dados recebidos
  return SPDR;
}

int main(void) {
  spi_init();
  char receivedData;

  while (1) {
    // Aguardar e processar as mensagens do mestre
    receivedData = spi_receive();

    switch (receivedData) {
      case 'A':
        // Acender o LED 13 (pino 13)
        PORTB |= (1 << PB7);
        break;
      case 'B':
        // Acender o LED 12 (pino 12)
        PORTB |= (1 << PB6);
        break;
      case 'C':
        // Acender o LED 11 (pino 11)
        PORTB |= (1 << PB5);
        break;
      default:
        break;
    }
  }
}
