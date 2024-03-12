/*
 * File:   7seg_4em1.c
 * Author: rodrigorimoldi
 *
 * Created on July 6, 2022, 8:51 PM
 */

#include "PIC18F_config.h"

#define timer1  840
#define timer2  40
#define pinD3   PORTCbits.RC0
#define pinD2   PORTCbits.RC1
#define pinD1   PORTCbits.RC2
#define pinD0   PORTCbits.RC3
#define segDP   PORTDbits.RD0
#define selA00  PORTAbits.RA3
#define selA01  PORTAbits.RA2

void numero_0 (void) {
    pinD3 = 0;
    pinD2 = 0;
    pinD1 = 0;
    pinD0 = 0;
}

void numero_1 (void) {
    pinD3 = 0;
    pinD2 = 0;
    pinD1 = 0;
    pinD0 = 1;
}

void numero_2 (void) {
    pinD3 = 0;
    pinD2 = 0;
    pinD1 = 1;
    pinD0 = 0;
}

void numero_3 (void) {
    pinD3 = 0;
    pinD2 = 0;
    pinD1 = 1;
    pinD0 = 1;
}

void numero_4 (void) {
    pinD3 = 0;
    pinD2 = 1;
    pinD1 = 0;
    pinD0 = 0;
}

void numero_5 (void) {
    pinD3 = 0;
    pinD2 = 1;
    pinD1 = 0;
    pinD0 = 1;
}

void numero_6 (void) {
    pinD3 = 0;
    pinD2 = 1;
    pinD1 = 1;
    pinD0 = 0;
}

void numero_7 (void) {
    pinD3 = 0;
    pinD2 = 1;
    pinD1 = 1;
    pinD0 = 1;
}

void numero_8 (void) {
    pinD3 = 1;
    pinD2 = 0;
    pinD1 = 0;
    pinD0 = 0;
}

void numero_9 (void) {
    pinD3 = 1;
    pinD2 = 0;
    pinD1 = 0;
    pinD0 = 1;
}

void display_7seg1 (void) {
    selA00 = 0;
    selA01 = 0;
}

void display_7seg2 (void) {
    selA00 = 1;
    selA01 = 0;
}

void display_7seg3 (void) {
    selA00 = 0;
    selA01 = 1;
}

void display_7seg4 (void) {
    selA00 = 1;
    selA01 = 1;
}

void main(void) {
    
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 0;
    TRISC = 0x00;
    TRISDbits.TRISD0 = 0;
    
    segDP = 1;
    
    for(;;) {
        display_7seg1();
        numero_0();
        __delay_ms(timer2);
        display_7seg2();
        numero_0();
        __delay_ms(timer2);
        display_7seg3();
        numero_0();
        __delay_ms(timer2);
        display_7seg4();
        numero_0();
        __delay_ms(timer2);
        segDP = !segDP;
        __delay_ms(timer1);
        
        display_7seg1();
        numero_1();
        __delay_ms(timer2);
        display_7seg2();
        numero_1();
        __delay_ms(timer2);
        display_7seg3();
        numero_1();
        __delay_ms(timer2);
        display_7seg4();
        numero_1();
        __delay_ms(timer2);
        segDP = !segDP;
        __delay_ms(timer1);
        
        display_7seg1();
        numero_2();
        __delay_ms(timer2);
        display_7seg2();
        numero_2();
        __delay_ms(timer2);
        display_7seg3();
        numero_2();
        __delay_ms(timer2);
        display_7seg4();
        numero_2();
        __delay_ms(timer2);
        segDP = !segDP;
        __delay_ms(timer1);
        
        display_7seg1();
        numero_3();
        __delay_ms(timer2);
        display_7seg2();
        numero_3();
        __delay_ms(timer2);
        display_7seg3();
        numero_3();
        __delay_ms(timer2);
        display_7seg4();
        numero_3();
        __delay_ms(timer2);
        segDP = !segDP;
        __delay_ms(timer1);
        
        display_7seg1();
        numero_4();
        __delay_ms(250);
        display_7seg2();
        numero_4();
        __delay_ms(250);
        display_7seg3();
        numero_4();
        __delay_ms(250);
        display_7seg4();
        numero_4();
        __delay_ms(250);
        segDP = !segDP;
        __delay_ms(timer1);
        
        display_7seg1();
        numero_5();
        __delay_ms(250);
        display_7seg2();
        numero_5();
        __delay_ms(250);
        display_7seg3();
        numero_5();
        __delay_ms(250);
        display_7seg4();
        numero_5();
        __delay_ms(250);
        segDP = !segDP;
        __delay_ms(timer1);
        
        display_7seg1();
        numero_6();
        __delay_ms(250);
        display_7seg2();
        numero_6();
        __delay_ms(250);
        display_7seg3();
        numero_6();
        __delay_ms(250);
        display_7seg4();
        numero_6();
        __delay_ms(250);
        segDP = !segDP;
        __delay_ms(timer1);
        
        display_7seg1();
        numero_7();
        __delay_ms(250);
        display_7seg2();
        numero_7();
        __delay_ms(250);
        display_7seg3();
        numero_7();
        __delay_ms(250);
        display_7seg4();
        numero_7();
        __delay_ms(250);
        segDP = !segDP;
        __delay_ms(timer1);
        
        display_7seg1();
        numero_8();
        __delay_ms(250);
        display_7seg2();
        numero_8();
        __delay_ms(250);
        display_7seg3();
        numero_8();
        __delay_ms(250);
        display_7seg4();
        numero_8();
        __delay_ms(250);
        segDP = !segDP;
        __delay_ms(timer1);
        
        display_7seg1();
        numero_9();
        __delay_ms(250);
        display_7seg2();
        numero_9();
        __delay_ms(250);
        display_7seg3();
        numero_9();
        __delay_ms(250);
        display_7seg4();
        numero_9();
        __delay_ms(250);
        segDP = !segDP;
        __delay_ms(timer1);
    }
    return;
}