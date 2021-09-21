#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

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
