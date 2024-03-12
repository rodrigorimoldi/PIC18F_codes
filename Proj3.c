/*
 * Arquivo:     Proj3.c
 * Autor:       Prof. Rodrigo Rimoldi de Lima
 *
 * Criacao:     29 de março de 2020, 17:46
 * 
 * Descricao:   Codigo desenvolvido para acionar um display de 7 segmentos, seja
 *              ele catodo comum ou anodo comum. Neste sentido, numeros e letras
 *              podem ser impressos no display a cada segundo.
 * 
 * Display:     A(RB3), B(RB4), C(RB1), D(RB2), E(RB7), F(RB5), G(RB6) e DP(NC)
 */

// Inclusao de arquivos de biblioteca
#include "PIC18F_config.h"

// Definicao de parametros e constantes
#define timer   1000
#define seg_A   PORTDbits.RD1
#define seg_B   PORTDbits.RD0
#define seg_C   PORTCbits.RC3
#define seg_D   PORTCbits.RC2
#define seg_E   PORTCbits.RC1
#define seg_F   PORTCbits.RC0
#define seg_G   PORTAbits.RA5
#define seg_DP  PORTAbits.RA4

// Padrao do display de 7 segmentos
/*
 *       __A__
 *      |     |
 *      F     B
 *      |__G__|
 *      |     |
 *      E     C
 *      |__D__| .DP
 * 
 */

// Subrotinas de acionamento
//    OBS.: Verificar se anodo
//          ou catodo comum
void numero_0(void){
    seg_A = 0;
    seg_B = 0;
    seg_C = 0;
    seg_D = 0;
    seg_E = 0;
    seg_F = 0;
    seg_G = 1;
}

void numero_1(void){
    seg_A = 1;
    seg_B = 0;
    seg_C = 0;
    seg_D = 1;
    seg_E = 1;
    seg_F = 1;
    seg_G = 1;
}

void numero_2(void){
    seg_A = 0;
    seg_B = 0;
    seg_C = 1;
    seg_D = 0;
    seg_E = 0;
    seg_F = 1;
    seg_G = 0;
}

void numero_3(void){
    seg_A = 0;
    seg_B = 0;
    seg_C = 0;
    seg_D = 0;
    seg_E = 1;
    seg_F = 1;
    seg_G = 0;
}

void numero_4(void){
    seg_A = 1;
    seg_B = 0;
    seg_C = 0;
    seg_D = 1;
    seg_E = 1;
    seg_F = 0;
    seg_G = 0;
}

void numero_5(void){
    seg_A = 0;
    seg_B = 1;
    seg_C = 0;
    seg_D = 0;
    seg_E = 1;
    seg_F = 0;
    seg_G = 0;
}

void numero_6(void){
    seg_A = 0;
    seg_B = 1;
    seg_C = 0;
    seg_D = 0;
    seg_E = 0;
    seg_F = 0;
    seg_G = 0;
}

void numero_7(void){
    seg_A = 0;
    seg_B = 0;
    seg_C = 0;
    seg_D = 1;
    seg_E = 1;
    seg_F = 1;
    seg_G = 1;
}

void numero_8(void){
    seg_A = 0;
    seg_B = 0;
    seg_C = 0;
    seg_D = 0;
    seg_E = 0;
    seg_F = 0;
    seg_G = 0;
}

void numero_9(void){
    seg_A = 0;
    seg_B = 0;
    seg_C = 0;
    seg_D = 0;
    seg_E = 1;
    seg_F = 0;
    seg_G = 0;
}

void main(void) {
    
    // Definição dos pinos de I/O
    TRISDbits.TRISD1 = 0;
    TRISDbits.TRISD0 = 0;
    TRISCbits.TRISC3 = 0;
    TRISCbits.TRISC2 = 0;
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC0 = 0;
    TRISAbits.TRISA5 = 0;
    TRISAbits.TRISA4 = 0;
    
    seg_DP = 1;
    
    // Loop infinito
    do{
        numero_0();
        seg_DP = !seg_DP;
        __delay_ms(timer);
        
        numero_1();
        seg_DP = !seg_DP;
        __delay_ms(timer);
        
        numero_2();
        seg_DP = !seg_DP;
        __delay_ms(timer);
        
        numero_3();
        seg_DP = !seg_DP;
        __delay_ms(timer);
        
        numero_4();
        seg_DP = !seg_DP;
        __delay_ms(timer);
        
        numero_5();
        seg_DP = !seg_DP;
        __delay_ms(timer);
        
        numero_6();
        seg_DP = !seg_DP;
        __delay_ms(timer);
        
        numero_7();
        seg_DP = !seg_DP;
        __delay_ms(timer);
        
        numero_8();
        seg_DP = !seg_DP;
        __delay_ms(timer);
        
        numero_9();
        seg_DP = !seg_DP;
        __delay_ms(timer);
        
    } while(1);
}