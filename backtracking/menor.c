#include <stdio.h>

#define MAX_N 20
#define MAX_M 20

int menorPassos = -1;

void labirinto_recursivo(int labirinto[MAX_N][MAX_M], int linha, int coluna, int controleLinha, int controleColuna, int passos) {
    if (controleLinha == -1 || controleColuna == -1 || controleLinha == linha || controleColuna == coluna || labirinto[controleLinha][controleColuna] != 0) {
        return;
    }

    if (controleLinha == linha - 1 && controleColuna == coluna - 1) {
        if (menorPassos == -1 || passos < menorPassos) {
            menorPassos = passos;
        }
        return;
    }

    labirinto[controleLinha][controleColuna] = 1;

    labirinto_recursivo(labirinto, linha, coluna, controleLinha + 1, controleColuna, passos + 1); // Movimento para baixo
    labirinto_recursivo(labirinto, linha, coluna, controleLinha - 1, controleColuna, passos + 1); // Movimento para cima
    labirinto_recursivo(labirinto, linha, coluna, controleLinha, controleColuna + 1, passos + 1); // Movimento para direita
    labirinto_recursivo(labirinto, linha, coluna, controleLinha, controleColuna - 1, passos + 1); // Movimento para esquerda

    labirinto[controleLinha][controleColuna] = 0;
}

int main() {
    int linha, coluna, labirinto[MAX_N][MAX_M];

    scanf("%d %d", &linha, &coluna);

    for (int i = 0; i < linha; ++i) {
        for (int j = 0; j < coluna; ++j) {
            scanf("%d", &labirinto[i][j]);
        }
    }

    labirinto_recursivo(labirinto, linha, coluna, 0, 0, 1); // Inicia a busca a partir do ponto de entrada (0, 0) com passos iniciais = 1

    printf("%d\n", menorPassos);

    return 0;
}
