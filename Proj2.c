/*
 * Arquivo:     Proj2.c
 * Autor:       Prof. Rodrigo Rimoldi de Lima
 *
 * Criacao:     29 de outubro de 2020, 16:18
 * 
 * Descricao:   Codigo desenvolvido para acionar um rele usando o mesmo algorit-
 *              mo desenvolvido para o projeto 1, porem com recursos de progra-
 *              macao diferentes.
 */

// Inclusao de arquivos de biblioteca
#include "PIC18F_config.h"

//Definicao de parametros
#define timer       1000
#define rele        PORTCbits.RC5
#define LED_PILOTO  PORTCbits.RC4

// Rotina principal
void main(void) {
    TRISC = 0x00;   //0b00000000
    
    LED_PILOTO = 0;
    rele = 1;

    while (1) {
        LED_PILOTO = !LED_PILOTO;
        rele = !rele;
        __delay_ms(timer);
    }
}