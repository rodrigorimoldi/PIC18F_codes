/* 
 * Arquivo:     ADC_config.h
 * Criado por:  Prof. Rodrigo Rimoldi de Lima
 * Criado em:   11/06/2018 - 09:22 AM
 */

// SUBROTINA DE CONFIGURACAO DA CONVERSAO A/D __________________________________
void Inicializa_ADC() {

    // Bits de selecao do clock do ADC
    ADCON1bits.ADCS2 = 1;
    ADCON0bits.ADCS1 = 1;
    ADCON0bits.ADCS0 = 0;
        // 000 = Fosc/2
        // 001 = Fosc/8
        // 010 = Fosc/32
        // 011 = O clock deriva do oscilador interno
        // 100 = Fosc/4
        // 101 = Fosc/16
        // 110 = Fosc/64
        // 111 = O clock deriva do oscilador interno

    // Bits de selecao dos canais de conversao A/D
    ADCON0bits.CHS2 = 0;
    ADCON0bits.CHS1 = 0;
    ADCON0bits.CHS0 = 0;
        // 000 = AN0 (pino 2)
        // 001 = AN1 (pino 3)
        // 010 = AN2 (pino 4)
        // 011 = AN3 (pino 5)
        // 100 = AN4 (pino 7)
        // 101 = AN5 (pino 8)
        // 110 = AN6 (pino 9)
        // 111 = AN7 (pino 10)

    // Bit de selecao do formato do resultado da conversao A/D
    ADCON1bits.ADFM = 0;
        // 1 = Justificado a direita
        // 0 = Justificado a esquerda

    // Bit de controle sobre a configuracao das portas A/D
    ADCON1bits.PCFG3 = 1;
    ADCON1bits.PCFG2 = 1;
    ADCON1bits.PCFG1 = 1;
    ADCON1bits.PCFG0 = 0;
        // Somente AN0 como entrada analagica
        // Vref+ = Vdd e Vref- = Vss

    // Bit de habilitacao da conversao A/D
    ADCON0bits.ADON = 1;
        // 1 = conversao A/D ligada
        // 0 = conversao A/D desligada    
}

// SUBROTINA DE RETORNO DO RESULTADO DA CONVERSAO A/D
unsigned int Leitura_ADC() {

    ADCON0bits.GO_nDONE = 1;
    while (GO_nDONE);

    if (ADFM) // Resultado justificado a direita
        return((ADRESH << 8) + ADRESL);
    else // Resultado justificado a esquerda
        return((ADRESH << 2) + (ADRESL >> 6));
}