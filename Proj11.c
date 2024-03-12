/* 
 * Arquivo:     Proj11.c
 * Autor:       Prof. Rodrigo Rimoldi de Lima
 * Criado em:   03/11/2020 - 16:56
 */

// INCLUSAO DE BIBLIOTECAS _____________________________________________________
#include "PIC18F_config.h"
#include "ADC_config.h"
#include "LCD16x2_config.h"
#include <stdio.h>

// DECLARACAO DE VARIAVEIS GLOBAIS _____________________________________________
unsigned char cBuffer1[16], cBuffer2[16];
unsigned int iResultado_ADC;
float fTensao, fTemperatura;


// ROTINA PRINCIPAL ____________________________________________________________
void main(void) {

    TRISA = 0x01;   // Apenas o pino RA0 configurado como entrada analogica

    Inicializa_LCD();
    Limpa_display_LCD();
    Escreve_texto_LCD("PIC ADC 10 bits ");
    Posicao_LCD(2, 1);
    Escreve_texto_LCD("UFTM MICRO 2024 ");
    __delay_ms(2000);
    Limpa_display_LCD();

    inicializa_ADC();

    do {

        iResultado_ADC = Leitura_ADC();
        __delay_ms(250);
        fTensao = (iResultado_ADC * 5.0) / 1024;
        //fTemperatura = fTensao * 100;
        Posicao_LCD(1, 1);
        sprintf(cBuffer1, "Tensao = %1.2f V", fTensao);
        Escreve_texto_LCD(cBuffer1);
        Posicao_LCD(2, 1);
        //sprintf(cBuffer2, "Temp = %3.1f C", fTemperatura);
        sprintf(cBuffer2, "Res_ADC = %u", iResultado_ADC);
        Escreve_texto_LCD(cBuffer2);
        iResultado_ADC = 0;
        fTensao = 0;
        __delay_ms(250);
    } while (1);
}