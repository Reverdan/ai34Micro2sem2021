#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is MCLR)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = ON          // Flash Program Memory Code Protection bit (0000h to 07FFh code-protected)

#include <xc.h>
#define _XTAL_FREQ 4000000

void configuracao()
{
    TRISB = 0x00; //Todo o portb como saída
    PORTB = 0x00;
}

void main()
{
    configuracao(); //Chama rotina de configuração acima
    for(;;) //Laço infinito
    {
        PORTB = 0x24;
        __delay_ms(2000);
        PORTB = 0x22;
        __delay_ms(1000);
        PORTB = 0x81;
        __delay_ms(2000);
        PORTB = 0x41;
        __delay_ms(1000);
    }
}

