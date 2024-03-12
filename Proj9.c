/* 
 * Arquivo:         Proj9.c
 * Criada por:      Prof. Rodrigo Rimoldi de Lima
 * Atualizada em:   03/11/2020 - 16:07
 */

// CHAMADA DE BIBLIOTECAS ______________________________________________________
#include "PIC18F_config.h"
#include "LCD16x2_config.h"
#include <stdio.h>

// DEFINICAO DE PARAMETROS E CONSTANTES ________________________________________
#define LED     PORTCbits.RC4
#define timer   3000

// DEFINICAO DE VARIAVEIS GLOBAIS ______________________________________________
char buffer[16];

// SUBROTINA DE CHAMADA DA INTERRUPCAO DE ESTOURO DO TMR0 ______________________
void __interrupt() int_TMR0(void) {

    if (TMR0IE && TMR0IF)
        TMR0IF = 0;
}

// ROTINA PRINCIPAL ____________________________________________________________
void main(void) {

    TRISAbits.TRISA4 = 1; // RA4 definido como entrada digital
    TRISCbits.TRISC4 = 0; // RC4 definido como saida digital
        
    T0CON = 0b11101001;
    /*      Bit 7   TMR0ON (bit de controle que liga/desliga o Timer0)
     *                  1 - Liga o timer
     *                  0 - Desliga o timer
     *      Bit 6   T08BIT (Bit que define o modo de operacao)
     *                  1 - Operacao em 8 bits
     *                  0 - Operacao em 16 bits
     *      Bit 5   T0CS (Bit de definicao da operacao como timer ou contador)
     *                  1 - Operacao como contador e transicao controlada pelo
     *                      pino T0CKI (pino 6, RA4)
     *                  0 - Operacao como timer e transicao controlada pelo
     *                      clock de maquina (Fosc/4)
     *      Bit 4   T0SE (Bit de selecao da borda de transicao para T0CKI)
     *                  1 - Incremento pela borda de descida
     *                  0 - Incremento pela borda de subida
     *      Bit 3   PSA (Bit de definicao do PRESCALER)
     *                  1 - PRESCALER desabilitado
     *                  0 - PRESCALER habilitado
     *      Bit 2-0 T0PS2:T0PS0 (Bits de selecao do PRESCALER)
     *                  111 - Escala de contagem 1:256
     *                  110 - Escala de contagem 1:128
     *                  101 - Escala de contagem 1:64
     *                  100 - Escala de contagem 1:32
     *                  011 - Escala de contagem 1:16
     *                  010 - Escala de contagem 1:8
     *                  001 - Escala de contagem 1:4
     *                  000 - Escala de contagem 1:2
     */
    INTCON = 0b10100000;
    /*      Bit 7   GIE/GIEH (bit de habilitacao global das interrupcoes)
     *                  1 - Habilita
     *                  0 - Desabilita
     *      Bit 5   TMR0IE (Bit de habilitacao da interrupcao do TMR0)
     *                  1 - Habilita
     *                  0 - Desabilita
     *      Bit 2   TMR0IF (Bits de flag da interrupcao do TMR0)
     *                  1 - Indica que ocorreu o estouro do TMR0
     *                  0 - Indica que ainda nao ocorreu o estouro do TMR0
     */
    INTCON2 = 0b10000100;
    /*      Bit 2   TMR0IP (bit de prioridade da interrupcao do TMR0)
     *                  1 - Alta prioridade
     *                  0 - Baixa prioridade
     */

    Inicializa_LCD();
    Limpa_display_LCD();

    TMR0 = 0;

    while (1) {
        Escreve_texto_LCD_com_pos(1, 1, "Contador PIC18  ");
        sprintf(buffer, "TMR0: %02u  ", TMR0);
        Escreve_texto_LCD_com_pos(2, 1, buffer);
        __delay_ms(30);

        if (TMR0 == 16) {
            Escreve_texto_LCD_com_pos(1, 1, "LIMITE ATINGIDO!");
            LED = 1;
            __delay_ms(timer);
            TMR0 = 0;
        } else
            LED = 0;
    }
}