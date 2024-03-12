/*
 * Arquivo:     Proj6.c
 * Autor:       Prof. Rodrigo Rimoldi de Lima
 *
 * Criado em:   3 de novembro de 2020, 13:33
 * 
 * Descricao:   Codigo desenvolvido para identificar duas entradas e exibir o 
 *              status de leitura na tela de um display LCD 16x2 em 4 bits.
 * 
 * Pinagem do LCD:  D7(RD7), D6(RD6), D5(RD5), D4(RD4), D3 a D0 (GND), RS(RC4),
 *                  R/W(GND), E(RC5)
 */

// DEFINICAO DE PARAMETROS E CONSTANTES ________________________________________
#define timer1      2000
#define timer2      50
#define ENTRADA1    PORTBbits.RB1
#define ENTRADA2    PORTBbits.RB2
#define LED         PORTCbits.RC4

// INCLUSÃO DE BIBLIOTECAS _____________________________________________________
#include "PIC18F_config.h"
#include "LCD16x2_config.h"

// ROTINA PRINCIPAL ____________________________________________________________

void main(void) {

    TRISB = 0b00000110;     // Pinos RB1 e RB2 como entradas
    TRISCbits.TRISC4 = 0;   // Pino do LED
    LED = 1;

    Inicializa_LCD();

    Escreve_texto_LCD_com_pos(1, 1, "DEE - MICRO/2024");
    Escreve_texto_LCD_com_pos(2, 1, "**** AULA 6 ****");
    __delay_ms(timer1);
    Escreve_texto_LCD_com_pos(2, 1, "Aguardando IN...");
    __delay_ms(timer1);

    for (;;) {
        while (ENTRADA1 && !ENTRADA2)
            Escreve_texto_LCD_com_pos(2, 1, " Entrada 1 = ON ");
        while (!ENTRADA1 && ENTRADA2)
            Escreve_texto_LCD_com_pos(2, 1, " Entrada 2 = ON ");
        while (ENTRADA1 && ENTRADA2)
            Escreve_texto_LCD_com_pos(2, 1, " 2 entradas ON  ");
        while (!ENTRADA1 && !ENTRADA2)
            Escreve_texto_LCD_com_pos(2, 1, " 2 entradas OFF ");
    }
}