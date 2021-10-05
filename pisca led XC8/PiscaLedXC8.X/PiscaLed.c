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

#define vermelho PORTBbits.RB0
#define amarelo PORTBbits.RB1
#define verde PORTBbits.RB2

#define vermelho2 PORTBbits.RB5
#define amarelo2 PORTBbits.RB6
#define verde2 PORTBbits.RB7

#define apaga_verde verde = 0
#define acende_verde verde = 1
#define apaga_amarelo amarelo = 0
#define acende_amarelo amarelo = 1
#define apaga_vermelho vermelho = 0
#define acende_vermelho vermelho = 1

#define apaga_verde2 verde2 = 0
#define acende_verde2 verde2 = 1
#define apaga_amarelo2 amarelo2 = 0
#define acende_amarelo2 amarelo2 = 1
#define apaga_vermelho2 vermelho2 = 0
#define acende_vermelho2 vermelho2 = 1

const int tempo = 1000;

void configuracao()
{
//    TRISB0 = 0; //Configura RB0 como saída - vermelho
//    TRISB1 = 0; //Configura RB2 como saída - amarelo
//    TRISB2 = 0; //Configura RB4 como saída - verde
    
    TRISB = 0x00; //Todo o portb como saída
    apaga_verde; 
    apaga_amarelo; 
    apaga_vermelho; 
    apaga_verde2; 
    apaga_amarelo2; 
    apaga_vermelho2; 
}

void main()
{
    configuracao(); //Chama rotina de configuração acima
    for(;;) //Laço infinito
    {
        acende_verde;
        acende_vermelho2;
        __delay_ms(2000);
        apaga_verde;
        acende_amarelo;
        __delay_ms(1000);
        apaga_amarelo;
        acende_vermelho;
        apaga_vermelho2;
        acende_verde2;
        __delay_ms(2000);
        apaga_verde2;
        acende_amarelo2;
        __delay_ms(1000);
        apaga_amarelo2;
        acende_vermelho2;
        apaga_vermelho;
        acende_verde;
        __delay_ms(2000);
    }
}
