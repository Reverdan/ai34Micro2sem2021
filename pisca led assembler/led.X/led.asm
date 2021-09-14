#include "p16f628a.inc"

RES_VECT  CODE    0x0000            
    GOTO    START                   

MAIN_PROG CODE                      

START
 
 
TEMPO	EQU 0X00 ;Cria variável tempo
TEMPO1	EQU 0X01 ;Cria variável tempo1
GOTO CONFIGURACAO ;Pula para configuração
	
DELAY:
    DECF TEMPO ;decrementa variável tempo
    BTFSC STATUS, Z ;Testa Z, pula se 0 - Pula a próxima linha
    RETURN ;Retorna para quem chamou
    CALL DELAY1 ;Chama Delay1
    GOTO DELAY ;Volta para Delay
    
DELAY1:
    DECF TEMPO1 ;Decrementa tempo1
    BTFSC STATUS, Z ;Testa Z, pula se 0 - Pula a próxima linha 
    RETURN ;Retorna para quem chamou
    GOTO DELAY1 ;Volta para Delay1
 
CONFIGURACAO: 
    ;Mudar para banco 1 - Configurar rb0 como saida - trisb.0 = 0
    BSF STATUS, RP0 ;Mudei para banco 1
    BCF TRISB, RB0 ;Configurei rb0 como saida
    BCF	STATUS, RP0 ;Voltei para banco 0
    BCF PORTB, RB0 ;rb0 comeca com 0, led apagado
    
INICIO:
    BSF PORTB, RB0 ;Nivel 1 em rb0
    CALL DELAY ;Chama delay
    BCF	PORTB, RB0 ;Nivel 0 em rb0
    CALL DELAY ;Chama delay
    GOTO INICIO ;Volta para inicio         

    END