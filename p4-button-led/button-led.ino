void setup()
{
  // PB1 entrada (0) e PB5 saida (1)
  // 0010 0000 = 0x20
  DDRB = 0x20;
}

void loop()
{
  	// Ler estado localizado no pino PB1
  	if ((PINB >> PB1) & 0x01) {
      	// PB5 liga (bit = 1)
      	PORTB |= (1 << PB5);
    } else {
      	// PB5 desliga (bit = 0)
      	PORTB &= ~(1 << PB5);
    }
}