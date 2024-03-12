/*
 * File:   tec_matricial.c
 * Author: rodrigorimoldi
 *
 * Created on July 5, 2022, 10:47 AM
 */


#include "PIC18F_config.h"
#include "LCD16x2_config.h"

#define timer   2000
#define lin1    PORTBbits.RB1
#define lin2    PORTBbits.RB2
#define lin3    PORTBbits.RB3
#define lin4    PORTBbits.RB4
#define col3    PORTBbits.RB5
#define col2    PORTBbits.RB6
#define col1    PORTBbits.RB7

void main(void) {

    // Definicao dos pinos de I/O
    TRISB = 0b00011111; // Linhas como entradas e colunas como saidas

    Inicializa_LCD();

    Limpa_display_LCD();
    Escreve_texto_LCD("DEE - MICRO/2024");
    Posicao_LCD(2, 1);
    Escreve_texto_LCD("RODRIGO RIMOLDI");
    __delay_ms(timer);
    Limpa_display_LCD();
    Escreve_texto_LCD("**** PROJ 1 ****");
    Escreve_texto_LCD_com_pos(2, 1, " TEC. MATRICIAL ");
    __delay_ms(timer);
    Limpa_display_LCD();
    
    // Laço infinito
    for (;;) {
        Escreve_texto_LCD_com_pos(1, 1, "TECLA ESCOLHIDA:");
        
        // Varredura 1
        col1 = 1;
        col2 = 0;
        col3 = 0;
        
        if(lin1) {
            Escreve_texto_LCD_com_pos(2, 1, "1");
            __delay_us(20);
            while(lin1){}
        }
        if(lin2) {
            Escreve_texto_LCD_com_pos(2, 1, "4");
            __delay_us(20);
            while(lin2){}
        }
        if(lin3) {
            Escreve_texto_LCD_com_pos(2, 1, "7");
            __delay_us(20);
            while(lin3){}
        }
        if(lin4) {
            Escreve_texto_LCD_com_pos(2, 1, "*");
            __delay_us(20);
            while(lin4){}
        }

        // Varredura 2
        col1 = 0;
        col2 = 1;
        col3 = 0;
        
        if(lin1) {
            Escreve_texto_LCD_com_pos(2, 2, "2");
            __delay_us(20);
            while(lin1){}
        }
        if(lin2) {
            Escreve_texto_LCD_com_pos(2, 2, "5");
            __delay_us(20);
            while(lin2){}
        }
        if(lin3) {
            Escreve_texto_LCD_com_pos(2, 2, "8");
            __delay_us(20);
            while(lin3){}
        }
        if(lin4) {
            Escreve_texto_LCD_com_pos(2, 2, "0");
            __delay_us(20);
            while(lin4){}
        }

        // Varredura 3
        col1 = 0;
        col2 = 0;
        col3 = 1;
        
        if(lin1) {
            Escreve_texto_LCD_com_pos(2, 3, "3");
            __delay_us(20);
            while(lin1){}
        }
        if(lin2) {
            Escreve_texto_LCD_com_pos(2, 3, "6");
            __delay_us(20);
            while(lin2){}
        }
        if(lin3) {
            Escreve_texto_LCD_com_pos(2, 3, "9");
            __delay_us(20);
            while(lin3){}
        }
        if(lin4) {
            Escreve_texto_LCD_com_pos(2, 3, "#");
            __delay_us(20);
            while(lin4){}
        }
        
        // Varredura 4
        col1 = 1;
        col2 = 1;
        col3 = 0;
        
        if(lin1 && lin2) {
            Escreve_texto_LCD_com_pos(2, 1, "BLOQUEADO");
            __delay_us(20);
            while(lin1 && lin2){}
        }
        if(lin2 && lin3) {
            Escreve_texto_LCD_com_pos(2, 1, "BLOQUEADO");
            __delay_us(20);
            while(lin2 && lin3){}
        }
        if(lin3 && lin1) {
            Escreve_texto_LCD_com_pos(2, 1, "BLOQUEADO");
            __delay_us(20);
            while(lin3 && lin1){}
        }
        if(lin4) {
            Escreve_texto_LCD_com_pos(2, 1, "*");
            __delay_us(20);
            while(lin4){}
        }
    }
    return;
}