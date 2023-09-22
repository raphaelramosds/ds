/**
 | --------------------------------------------------------
 | Lista 6
 | --------------------------------------------------------
 | Autores: Raphael Ramos
 |
 | µControlador: ATmega2560
 |
*/

#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB7  // Define o pino do LED

void initPWM() {
    // Configurar o Timer 0 no modo Fast PWM
    TCCR0A |= (1 << COM0A1) | (1 << WGM00) | (1 << WGM01);
    TCCR0B |= (1 << CS00);  // Prescaler = 1

    // Configurar o pino do LED como saída
    DDRB |= (1 << LED_PIN);
}

void setPWM(float duty) {
    // OCR0A tem 8 bits entao o TOP pode ser ate 256
    // No PWM, quanto menor OCR0A, menor sera o duty cycle
    // caso ele esteja no modo direto. Entao, duty eh uma
    // porcentagem do duty cycle que queremos  
    OCR0A = (int) (duty * 256) - 1;
}

int main() {
    initPWM();

    while (1) {
        // Duty cycle = 0.1%
        setPWM(0.01);
        _delay_ms(300);

        // Duty cycle = 25%
        setPWM(0.25);
        _delay_ms(200);

        // Duty cycle = 50%
        setPWM(0.5);
        _delay_ms(200);

        // Duty cycle = 75%
        setPWM(0.75);
        _delay_ms(200);

        // Duty cycle = 100%
        setPWM(1.0);
        _delay_ms(200);
    }

    return 0;
}

