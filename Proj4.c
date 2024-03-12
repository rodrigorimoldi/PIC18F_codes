/*
 * Arquivo:     Proj4.c
 * Autor:       Prof. Rodrigo Rimoldi de Lima
 *
 * Criacao:     23 de Março de 2019, 16:03
 * 
 * Descricao:   Codigo desenvolvido para acionar um display LCD 16x2 em 4 bits.
 * 
 * Pinagem do LCD:  D7(RD7), D6(RD6), D5(RD5), D4(RD4), D3 a D0 (GND), RS(RC4),
 *                  R/W(GND), E(RC5)
 */

// DEFINICAO DE PARAMETROS E CONSTANTES ________________________________________
#pragma config OSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF

#define _XTAL_FREQ  20000000
#define timer       3000

// INCLUSAO DE BIBLIOTECAS _____________________________________________________
#include <xc.h>
#include <pic18f452.h>
#include "LCD16x2_config.h"

// ROTINA PRINCIPAL ____________________________________________________________
void main(void) {

    Inicializa_LCD(); // Inicializa o LCD

    // Laco infinito
    for (;;) {
        Limpa_display_LCD();
        Escreve_texto_LCD("DEE - MICRO/2024");
        Posicao_LCD(2, 1);
        Escreve_texto_LCD("RODRIGO RIMOLDI");
        __delay_ms(timer);
        Limpa_display_LCD();
        Escreve_texto_LCD("**** AULA 4 ****");
        Escreve_texto_LCD_com_pos(2, 1, "LCD: PROGRAMA 1 ");
        __delay_ms(timer);
        Limpa_display_LCD();
        Envia_dado_LCD(0xF2); // Caractere teta
        Posicao_LCD(2, 1);
        Envia_dado_LCD(0xE0); // Caractere alfa
        Posicao_LCD(1, 4);
        Envia_dado_LCD(0x7E); // Caractere seta para a direita
        Posicao_LCD(2, 4);
        Envia_dado_LCD(0xF4); // Caractere ômega 
        __delay_ms(timer);
    }
    return;
}