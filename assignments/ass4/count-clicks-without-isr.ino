/**
 | --------------------------------------------------------
 | Lista 4
 | --------------------------------------------------------
 | Autores: Raphael Ramos
 |
 | µControlador: Atmega328p
 |
 | Consideração: implementação feita com pull-out interno 
 | configurado nos pinos PB0 e PD4. Utilizou-se uma variável 
 | enable para que o display não fosse incrementado ao mantermos 
 | o botão pressionado.
*/

// g = PB1
// f = PB2
// a = PB4
// b = PB5
// e = PD7
// d = PD6
// c = PD5

// a b c d e f
void zero() {
	// PB5 PB4 PB2 [PB0] 
  	PORTB = 0x34 + 0x1;
  	// PD7 PD6 PD5 [PD4]
  	PORTD = 0xE0 + 0x10;
}

// b c
void one() {
	// PB5 [PB0]
  	PORTB = 0x20 + 0x1;
  	// PD5 [PD4]
  	PORTD = 0x20 + 0x10;
}

// a b g e d
void two() {
	// PB5 PB4 PB1 [PB0] 
  	PORTB = 0x32 + 0x1;
  	// PD7 PD6 [PD4]
  	PORTD = 0xC0 + 0x10;
}

// a b g c d
void three() {
	// PB5 PB4 PB1 [PB0]
  	PORTB = 0x32 + 0x1;
  	// PD6 PD5 [PD4]
  	PORTD = 0x60 + 0x10;
}

// f b g c
void four() {
	// PB5 PB2 PB1 [PB0]
	PORTB = 0x26 + 0x1;
	// PD5 [PD4]
	PORTD = 0x20 + 0x10;
}

// a f g c d
void five() {
	// PB4 PB2 PB1 [PB0]
  	PORTB = 0x16 + 0x1;
  	// PD6 PD5 [PD4]
  	PORTD = 0x60 + 0x10;
}

// a f e d c g
void six() {
	// PB4 PB2 PB1 [PB0]
  	PORTB = 0x16 + 0x1;
	// PD7 PD6 PD5 [PD4]
  	PORTD = 0xE0 + 0x10;
}

// a b c
void seven() {
	// PB5 PB4 [PB0]
  	PORTB = 0x30 + 0x1;
  	// PD5 [PD4]
  	PORTD = 0x20 + 0x10;
}

void setup()
{  
	DDRB = 0x36;
  	DDRD = 0xE0;
  	zero();
}

unsigned char count = 1;
bool enable = true;
void (*f[8])() = {zero, one, two, three, four, five, six, seven};

void loop(){
  // PD4 (pino 4) reseta
  if (~(PIND >> PD4) & 0x01) {
    delay(500);
  	zero();
    count = 1;
  }
  
  // PB0 (pino 8) Incrementa

  // Note. como PB0 tem resistor de pullout habilitado, 
  // sua entrada fica normalmente em +5V (o display incrementa). 
  // Então, apenas incremente se PB0 tiver nível zero (quando
  // apertarmos o botão). Por isso invertermos PINB >> PB0

  if (~(PINB >> PB0) & 0x01 && enable) {
    delay(500);
  	f[count]();
    count++;
    enable = false;
  }
  
  if ((PINB >> PB0) & 0x01 && !enable) {
  	enable = true;
  }
}
