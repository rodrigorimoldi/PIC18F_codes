/*
 * Arquivo:     Proj1.c
 * Autor:       Prof. Rodrigo Rimoldi de Lima
 *
 * Criacao:     29 de outubro de 2020, 15:19
 * 
 * Descricao:   Codigo desenvolvido para piscar um LED e desenvolver o
 *              primeiro contato com a IDE do MPLAB X.
 */

// Inclusao de arquivos de biblioteca
#include "PIC18F_config.h"

// Rotina principal
void main(void)
{
    // I/O - Configuracao de RD2 como saida
    TRISCbits.TRISC4 = 0;
    
    // I/O - Atribuicao de nivel logico baixo
    PORTD = 0x00;

    while(1)
    {
        PORTCbits.RC4 = 1;
        __delay_ms(1000);
        PORTCbits.RC4 = 0;
        __delay_ms(1000);
    }
}