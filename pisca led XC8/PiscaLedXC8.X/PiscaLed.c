#include <xc.h>
#define _XTAL_FREQ 4000000

void configuracao()
{
    TRISB0 = 0; //Configura RB0 como saída - vermelho
    TRISB2 = 0; //Configura RB2 como saída - amarelo
    TRISB4 = 0; //Configura RB4 como saída - verde
    PORTBbits.RB0 = 0; // Inicializa vermelho apagado
    PORTBbits.RB2 = 0; // Inicializa amarelo apagado
    PORTBbits.RB4 = 0; // Inicializa verde apagado
}

void main()
{
    configuracao(); //Chama rotina de configuração acima
    for(;;) //Laço infinito
    {
        PORTBbits.RB4 = 0x00; //Apaga verde
        PORTBbits.RB0 = 0x01; //Acende vermelho
        __delay_ms(1000); //Atraso
        PORTBbits.RB0 = 0x00; //Apaga verde
        PORTBbits.RB2 = 0x01; //Acende amarelo
        __delay_ms(200); //Atraso
        PORTBbits.RB2 = 0x00; //Apaga amarelo
        PORTBbits.RB4 = 0x01; //Acende verde
        __delay_ms(1500); //Atraso
    }
}
