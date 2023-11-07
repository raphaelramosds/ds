#include <avr/io.h>
#include <util/delay.h>

void ADC_Init() {
    // Configurar a porta A0 como entrada analógica
    // Usar referência de tensão AVCC com ajuste à direita
    ADMUX = (1 << REFS0);

    // Habilitar o conversor A/D e definir o divisor de frequência para 128
    // Isso define a taxa de amostragem em cerca de 125 kHz (16 MHz / 128)
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}

uint16_t ADC_Read(uint8_t channel) {
    // Selecionar o canal analógico (A0 = 0, A1 = 1, etc.)
    ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);

    // Iniciar a conversão
    ADCSRA |= (1 << ADSC);

    // Aguardar o término da conversão
    // Observacao. ADSC se torna zero apos a conversao
    while (ADCSRA & (1 << ADSC));

    // Retornar o valor convertido (16 bits)
    return ADC;
}

int main(void) {
    // Inicializar o sistema
    ADC_Init();

    float AVCC = 4.7;
    int ADC_BITS = 1024;

    Serial.begin(9600);

    while (1) 
    {
      Serial.println(ADC_Read(0)*AVCC/ADC_BITS);
    }

    return 0;
}
