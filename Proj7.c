/* 
 * Arquivo:         Proj7.c
 * Criada por:      Prof. Rodrigo Rimoldi de Lima
 * Atualizada em:   03/11/2020 - 15:24
 */

// CHAMADA DE BIBLIOTECAS ______________________________________________________
#include "PIC18F_config.h"
#include "LCD16x2_config.h"

// DEFINICAO DE PARAMETROS E CONSTANTES ________________________________________
#define LED     PORTCbits.RC4
#define timer   750

// SUBROTINA DE CHAMADA DA INTERRUPCAO EXTERNA EM RB0 __________________________
void __interrupt() intExt_RB0(void) {

    if (INT0IE && INT0IF) {

        LED = 1;
        Posicao_LCD(2, 1);
        Escreve_texto_LCD("Int. RB0 ATIVA  ");
        __delay_ms(timer);

        INT0IF = 0;
    }
}

// ROTINA PRINCIPAL ____________________________________________________________

void main(void) {

    TRISB = 0x01;               // Apenas RB0 como entrada digital
    TRISCbits.TRISC4 = 0;       // Pino do LED

    INTCON2bits.INTEDG0 = 1;    // Habilita o bit de selecao da borda de INTE
        // INTEDG = 1 (borda de subida)
        // INTEDG = 0 (borda de descida)
    INTCONbits.INT0IF = 0;      // Flag identificador de ocorrencia para INT0IE
        // INT0IF = 1 (interrupcao ocorreu)
        // INT0IF = 0 (interrupcao não ocorreu)
    INTCONbits.INT0IE = 1;      // Habilita o bit de interrupcao externa no pino RB0
    INTCONbits.GIE = 1;         // Habilita o bit global de interrupcoes (GIE)
    
    Inicializa_LCD();           // Inicializacao do LCD
    Limpa_display_LCD();
    Escreve_texto_LCD("DEE - MICRO/2024");

    while (1) {
        LED = 0;
        Posicao_LCD(2, 1);
        Escreve_texto_LCD("Int. RB0 INATIVA");
        __delay_ms(timer);
    }
}