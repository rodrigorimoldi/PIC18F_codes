/*
 * Arquivo:     Proj5.c
 * Autor:       Prof. Rodrigo Rimoldi de Lima
 *
 * Criado em:   2 de novembro de 2020, 22:22
 * 
 * Descricao:   Codigo desenvolvido para criar novos caracteres no acionamento 
 *              de um display LCD 16x2 em 4 bits.
 * 
 * Pinagem do LCD:  D7(RD7), D6(RD6), D5(RD5), D4(RD4), D3 a D0 (GND), RS(RC4),
 *                  R/W(GND), E(RC5)
 */

// DEFINICAO DE PARAMETROS E CONSTANTES ________________________________________
#define timer   5000
#define LED     PORTCbits.RC4

// INCLUSAO DE BIBLIOTECAS _____________________________________________________
#include "PIC18F_config.h"
#include "LCD16x2_config.h"

// NOVOS CARACTERES ____________________________________________________________
const char smile[8] = {
    0b00000000,
    0b00001010,
    0b00001010,
    0b00001010,
    0b00000000,
    0b00010001,
    0b00001110,
    0b00000000,
};

const char smile2[8] = {
    0b00000000,
    0b00001010,
    0b00001010,
    0b00001010,
    0b00000100,
    0b00010001,
    0b00001110,
    0b00000000,
};

const char pacmanopen[] = {0x0E, 0x07, 0x03, 0x01, 0x03, 0x07, 0x0E, 0x00, '\n'};

const char pacmanshut[] = {0x00, 0x0E, 0x1F, 0x01, 0x1F, 0x0E, 0x00, 0x00, '\n'};

// ROTINA PRINCIPAL ____________________________________________________________

void main(void) {
    
    TRISCbits.TRISC4 = 0;   // Pino do LED
    LED = 1;

    Inicializa_LCD();

    do {
        Limpa_display_LCD();
        Escreve_texto_LCD("DEE - MICRO/2024");
        Escreve_texto_LCD_com_pos(2, 1, "RODRIGO RIMOLDI");
        __delay_ms(timer);

        Limpa_display_LCD();
        Escreve_texto_LCD("**** AULA 5 ****");
        Posicao_LCD(2, 1);
        Escreve_texto_LCD("LCD: PROGRAMA 2");
        __delay_ms(timer);

        Limpa_display_LCD();
        Envia_dado_LCD(0xF4);
        Posicao_LCD(2, 1);
        Envia_dado_LCD(0xCE);
        __delay_ms(timer);

        Novo_caractere_LCD(0, pacmanopen);
        Posicao_LCD(1, 4);
        Envia_dado_LCD(0);
        Novo_caractere_LCD(1, pacmanshut);
        Posicao_LCD(2, 4);
        Envia_dado_LCD(1);
        __delay_ms(timer);

        Novo_caractere_LCD(2, smile);
        Posicao_LCD(1, 7);
        Envia_dado_LCD(2);
        Novo_caractere_LCD(3, smile2);
        Posicao_LCD(2, 7);
        Envia_dado_LCD(3);
        __delay_ms(timer);

    } while (1);
}