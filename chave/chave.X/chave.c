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

#define chave PORTAbits.RA1
#define led PORTBbits.RB0
#define acende_led led = 1;
#define apaga_led led = 0;

void configuracao()
{
    TRISA1 = 1;
    TRISB0 = 0;
    apaga_led;
}

void pisca_led()
{
    acende_led;
    __delay_ms(1000);
    apaga_led;
    __delay_ms(1000);
}

void main()
{
    configuracao();
    for(;;)
    {
        
        if (chave == 0)
        {
            __delay_ms(10);
            pisca_led();
        }
    }
}
