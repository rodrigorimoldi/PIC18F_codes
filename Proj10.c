/* 
 * Arquivo:         Proj10.c
 * Criada por:      Prof. Rodrigo Rimoldi de Lima
 * Atualizada em:   03/11/2020 - 16:41
 */

// CHAMADA DE BIBLIOTECAS ______________________________________________________
#include "PIC18F_config.h"
#include "LCD16x2_config.h"
#include <stdio.h>

// DEFINICAO DE PARAMETROS E CONSTANTES ________________________________________
#define LED     PORTCbits.RC4
#define timer   1000

// DEFINIÇÃO DE VARIAVEIS GLOBAIS ______________________________________________
char buffer[16];
unsigned int min, sec, trigger;

// SUBROTINA DE CHAMADA DA INTERRUPCAO DE ESTOURO DO TMR0 ______________________
void __interrupt() int_TMR0_EXT_RB0(void) {

    static unsigned int k;

    if (INT0IE && INT0IF) {

        INT0IF = 0;
        TMR0IE = 1;
        trigger = 1;
    }

    if (TMR0IE && TMR0IF) {

        TMR0IF = 0;
        k++;

        if (k == 76) {

            k = 0;
            sec--;
            LED = !LED;
        }
    }
}

// ROTINA PRINCIPAL ____________________________________________________________
void main(void) {

    TRISBbits.TRISB0 = 1;
    TRISCbits.TRISC4 = 0;
    
    T0CON = 0b11000111;
    INTCON = 0b10010000;
    INTCON2 = 0b11000000;

    min = 1;
    sec = 59;
    trigger = 0;

    Inicializa_LCD();
    Limpa_display_LCD();
    Posicao_LCD(1, 1);
    Escreve_texto_LCD("Timer PIC INTEXT");
    Posicao_LCD(2, 1);
    Escreve_texto_LCD("02:00");
    __delay_ms(timer);

    while (1) {

        if (trigger) {
            if (min == 1) {

                if (sec) {
                        sprintf(buffer, "01:%02u", sec);
                        Posicao_LCD(2, 1);
                        Escreve_texto_LCD(buffer);
                } else {

                    min = 0;
                    sec = 59;
                }
            } else {

                if (sec) {
                        sprintf(buffer, "00:%02u", sec);
                        Posicao_LCD(2, 1);
                        Escreve_texto_LCD(buffer);
                } else {

                    T0IE = 0;
                    Posicao_LCD(2, 1);
                    Escreve_texto_LCD("Time OVER");
                }
            }
        }
    }
}