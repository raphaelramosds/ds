// ========================================================================
// Lista 8
// ========================================================================
// Autor: Raphael Ramos
// µControlador: ATmega2560
// ========================================================================

#include <avr/io.h>
#include <util/delay.h>

void spi_init() {
  // Configurar o mestre
  // Configurar SCK, MOSI, SS como saídas
  DDRB = (1 << DDB5) | (1 << DDB3) | (1 << DDB2);
  
  // Habilitar SPI, mestre, taxa de transmissão = Fosc/16
  SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

void spi_transmit(char data) {
  // Iniciar transmissão
  SPDR = data;
  
  // Aguardar a transmissão ser concluída
  while (!(SPSR & (1 << SPIF)));
}

int main(void) {
  spi_init();
  char message;

  while (1) {
    // Enviar mensagens 'A', 'B', 'C'
    message = 'A';
    spi_transmit(message);
    _delay_ms(1000);

    message = 'B';
    spi_transmit(message);
    _delay_ms(1000);

    message = 'C';
    spi_transmit(message);
    _delay_ms(1000);
  }
}
