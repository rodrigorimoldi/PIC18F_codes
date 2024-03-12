/* 
 * Arquivo:         LCD16x2_config.h
 * Criada por:      tutorialesvirtuales.com / rgt90@hotmail.com
 * Adaptada por:    Prof. Rodrigo Rimoldi de Lima
 * Atualizada em:   14/10/2017 - 12:06 AM
 */


// DEFINICOES __________________________________________________________________

// Nota 1: Biblioteca escrita para uma interface de comunicacao em 4 bits
// Nota 2: Basta alterar a pinagem (linhas 14 a 19) conforme conveniencia

#define TRISRS          TRISCbits.TRISC7    //Define o sentido do pino de RS
#define TRISE           TRISCbits.TRISC6    //Define o sentido do pino de E
#define RS              PORTCbits.RC7       // Define RS para o controle do LCD
#define E               PORTCbits.RC6       // Define E para o controle do LCD
#define Sentido_PORT    TRISD               //Define os pinos de dados D7 a D4
#define PORT_dados      PORTD


// PROTOTIPO DAS FUNCOES _______________________________________________________
void Inicializa_LCD();
void Envia_comando_LCD(char);
void Envia_dado_LCD(char);
void Limpa_display_LCD();
void Pos_inicial_LCD();
void Escreve_texto_LCD(char*);
void Escreve_texto_LCD_com_pos(int, int, char*);
void Posicao_LCD(int, int);
void Novo_caractere_LCD(char, char[]);
void Timer_LCD();

// SUBROTINA DE INICIALIZACAO DO LCD ___________________________________________

void Inicializa_LCD() {
    TRISRS = 0; // RS como saida
    TRISE = 0; // E como saida
    Sentido_PORT = 0b00001111; // Nibble mais significativo como saida (4 Bits)
    RS = 0; // Limpa RS
    E = 0; // Limpa E
    PORT_dados = 0; // Limpa os pinos de dados
    __delay_ms(50);
    Envia_comando_LCD(0x02); // Coloca o cursor do LCD na posicao inicial (Home)
    Envia_comando_LCD(0x28); // Configura a comunicacao em 4 bits 
    Envia_comando_LCD(0x0C); // Configura display ON e cursor OFF
    Envia_comando_LCD(0x06); // Desloca o cursor para posicao a direita
}

// SUBROTINA DE ENVIO DE COMANDOS ______________________________________________

void Envia_comando_LCD(char comando) {
    RS = 0;
    PORT_dados = comando & 0xF0;
    Timer_LCD();
    PORT_dados = ((comando & 0x0F) << 4);
    Timer_LCD();
    __delay_ms(2);
}

// SUBROTINA DE ENVIO DE DADOS _________________________________________________

void Envia_dado_LCD(char dado) {
    RS = 1;
    PORT_dados = dado & 0xF0;
    Timer_LCD();
    PORT_dados = ((dado & 0x0F) << 4);
    Timer_LCD();
    __delay_us(50);
}

// SUBROTINA DE LIMPEZA DO LCD _________________________________________________

void Limpa_display_LCD() {
    Envia_comando_LCD(0x01);
}

// SUBROTINA DE POSICIONAMENTO DO CURSOR NA POSICAO (1,1) ______________________

void Pos_inicial_LCD() {
    Envia_comando_LCD(0x02);
}

// SUBROTINA PARA ESCRITA DE TEXTOS ____________________________________________

void Escreve_texto_LCD(char *texto) {
    while (*texto) // Sera executado enquanto nao for nulo
    {
        Envia_dado_LCD(*texto); // Envia o texto ao LCD
        texto++; // Incrementa o buffer de posicionamento do texto
    }
}

// SUBROTINA PARA ESCRITA DE TEXTOS COM POSICAO DEFINIDA _______________________

void Escreve_texto_LCD_com_pos(int linha, int coluna, char *texto) {
    char pos;
    switch (linha) {
        case 1: pos = 0x80 + (coluna - 1);
            break;
        case 2: pos = 0xC0 + (coluna - 1);
            break;
        default: pos = 0x80 + (coluna - 1);
            break;
    }
    Envia_comando_LCD(pos);
    Escreve_texto_LCD(texto);
}

// SUBROTINA DE POSICIONAMENTO DO CURSOR EM UMA POSICAO QUALQUER _______________

void Posicao_LCD(int linha, int coluna) {
    char pos;
    switch (linha) {
        case 1: pos = 0x80 + (coluna - 1);
            break;
        case 2: pos = 0xC0 + (coluna - 1);
            break;
        default: pos = 0x80 + (coluna - 1);
            break;
    }
    Envia_comando_LCD(pos);
}

// SUBROTINA PARA CRIACAO DE NOVOS CARACTERES __________________________________

void Novo_caractere_LCD(char endereco, char caractere[]) {
    int i;
    Envia_comando_LCD(0x40 + (endereco * 8));
    for (i = 0; i < 8; i++) {
        Envia_dado_LCD(caractere[i]);
    }
}

// SUBROTINA DE POSICIONAMENTO DO CURSOR NA POSICAO (1,1) ______________________

void Timer_LCD() {
    E = 1;
    __delay_us(5);
    E = 0;
    __delay_us(5);
}