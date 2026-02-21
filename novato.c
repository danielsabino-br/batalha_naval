#include <stdio.h>

#define TAM 10        // Tamanho do tabuleiro (10x10)
#define NAVIO_TAM 3   // Tamanho fixo dos navios

int main() {

    // ================================
    // DECLARAÇÃO DO TABULEIRO
    // ================================
    
    int tabuleiro[TAM][TAM];   // Matriz 10x10
    int i, j;

    // Inicializa todas as posições com 0 (água)
    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    // ================================
    // DECLARAÇÃO DOS NAVIOS
    // ================================

    int navioHorizontal[NAVIO_TAM] = {3, 3, 3};
    int navioVertical[NAVIO_TAM]   = {3, 3, 3};

    // Coordenadas iniciais (definidas diretamente no código)
    int linhaH = 2, colunaH = 4;  // Navio Horizontal
    int linhaV = 5, colunaV = 7;  // Navio Vertical

    // ================================
    // VALIDAÇÃO DO NAVIO HORIZONTAL
    // ================================

    // Verifica se cabe no tabuleiro
    if(colunaH + NAVIO_TAM > TAM) {
        printf("Erro: Navio horizontal ultrapassa os limites!\n");
        return 1;
    }

    // Verifica sobreposição
    for(i = 0; i < NAVIO_TAM; i++) {
        if(tabuleiro[linhaH][colunaH + i] != 0) {
            printf("Erro: Navio horizontal sobrepõe outro navio!\n");
            return 1;
        }
    }

    // Posiciona o navio horizontal
    for(i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linhaH][colunaH + i] = navioHorizontal[i];
    }

    // ================================
    // VALIDAÇÃO DO NAVIO VERTICAL
    // ================================

    // Verifica se cabe no tabuleiro
    if(linhaV + NAVIO_TAM > TAM) {
        printf("Erro: Navio vertical ultrapassa os limites!\n");
        return 1;
    }

    // Verifica sobreposição
    for(i = 0; i < NAVIO_TAM; i++) {
        if(tabuleiro[linhaV + i][colunaV] != 0) {
            printf("Erro: Navio vertical sobrepõe outro navio!\n");
            return 1;
        }
    }

    // Posiciona o navio vertical
    for(i = 0; i < NAVIO_TAM; i++) {
        tabuleiro[linhaV + i][colunaV] = navioVertical[i];
    }

    // ================================
    // EXIBIÇÃO DO TABULEIRO
    // ================================

    printf("\nTABULEIRO BATALHA NAVAL\n\n");

    for(i = 0; i < TAM; i++) {
        for(j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}