#include <stdio.h>


//parametros:   labirinto,             qtd linhas, qtd colunas, pos Atual X e Y
int labirinto_bt(int labirinto[20][20], int linha, int coluna, int x, int y, int passos) {
    // Verifica se está fora dos limites ou se é uma barreira
    if (x == -1 || y == -1 || x == coluna || y == linha || labirinto[y][x] != 0) {
        return -1;  // Retorna -1 para indicar que não há saída
    }

    // Verifica se chegou à saída
    if (x == coluna - 1 && y == linha - 1) {
        return passos;  // Retorna o número de passos até a saída
    }

    // Marca a célula como visitada
    labirinto[y][x] = 9;

    // Explora as opções de movimento (acima, abaixo, esquerda, direita)
    int opcoes[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };
    int menor_passos = -1;

    for (int i = 0; i < 4; i++) {
        int nx = x + opcoes[i][0];
        int ny = y + opcoes[i][1];

        int resultado = labirinto_bt(labirinto, linha, coluna, nx, ny, passos + 1);

        // Atualiza o menor número de passos se encontrarmos um caminho válido
        if (resultado != -1 && (menor_passos == -1 || resultado < menor_passos)) {
            menor_passos = resultado;
        }
    }

    // Desmarca a célula, para que possa ser explorada por outras rotas
    labirinto[y][x] = 0;

    return menor_passos;
}


    int main()
{
    int linha, coluna, labirinto[20][20];
    scanf("%d %d", &linha, &coluna);
    for (int i = 0; i < linha; ++i)
        for (int j = 0; j < coluna; ++j)
            scanf("%d", &labirinto[i][j]);
    int saida = labirinto_bt(labirinto, linha,
                             coluna, 0, 0, 0);
    printf("%d\n"

           ,
           saida);

    return 0;
}