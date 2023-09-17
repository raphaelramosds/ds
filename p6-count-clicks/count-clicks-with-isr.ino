/**
 | --------------------------------------------------------
 | Lista 4
 | --------------------------------------------------------
 | Autores: Raphael Ramos
 |
 | µControlador: Atmega328p
 |
 | Consideração: implementação feita com pull-out físico
 | e com sinais de interrupções para incrementar (INT0) e
 | resetar a contagem (INT1), ambas na borda de subida
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
	// PB5 PB4 PB2 
  	PORTB = 0x34;
  	// PD7 PD6 PD5
  	PORTD = 0xE0;
}

// b c
void one() {
	// PB5
  	PORTB = 0x20;
  	// PD5
  	PORTD = 0x20;
}

// a b g e d
void two() {
	// PB5 PB4 PB1 
  	PORTB = 0x32;
  	// PD7 PD6
  	PORTD = 0xC0;
}

// a b g c d
void three() {
	// PB5 PB4 PB1
  	PORTB = 0x32;
  	// PD6 PD5 
  	PORTD = 0x60;
}

// f b g c
void four() {
	// PB5 PB2 PB1 
	PORTB = 0x26;
	// PD5
	PORTD = 0x20;
}

// a f g c d
void five() {
	// PB4 PB2 PB1
  	PORTB = 0x16;
  	// PD6 PD5
  	PORTD = 0x60;
}

// a f e d c g
void six() {
	// PB4 PB2 PB1
  	PORTB = 0x16;
	// PD7 PD6 PD5
  	PORTD = 0xE0;
}

// a b c
void seven() {
	// PB5 PB4
  	PORTB = 0x30;
  	// PD5
  	PORTD = 0x20;
}

void setup()
{  
  	// Ativa Status Register
  	sei();
  
  	// Ativar INT0 e INT1
  	EIMSK |= (1<<INT0);
  	EIMSK |= (1<<INT1);
  
  	// Interrupção de INT0 e INT1 na borda de subida
  	EICRA |= (1<<ISC01) | (1<<ISC00);
  	EICRA |= (1<<ISC11) | (1<<ISC10);
  
	DDRB = 0x36;
  	DDRD = 0xE0;
  	zero();
}

unsigned char count = 1;
void (*f[8])() = {zero, one, two, three, four, five, six, seven};

void loop(){}

// INT1 apenas acende o display na borda de subida
ISR(INT1_vect) {
  if (count < 8) {
    delay(1000);
    f[count]();
    count++;
  }
}

// INT0 reseta o display na borda de subida
ISR(INT0_vect) {
  zero();
  count = 1;
}