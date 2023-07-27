#include <stdio.h>

int labirinto_bt(int labirinto[20][20], int linha, int coluna, int controleLinha, int controleColuna, int passos){
    if(controleLinha == -1 || controleColuna == -1 || controleLinha == linha || controleColuna == coluna || labirinto[controleLinha][controleColuna] != 0)
        return 0;
    if(controleLinha == linha - 1 && controleColuna == coluna - 1) return 1;
    
    labirinto[controleLinha][controleColuna] = 9;

    int ans = 0;
    /*desce*/
    ans = labirinto_bt(labirinto, linha, coluna, controleLinha + 1, controleColuna, passos) ||  
          labirinto_bt(labirinto, linha, coluna, controleLinha, controleColuna + 1, passos) || 
          labirinto_bt(labirinto, linha, coluna, controleLinha - 1, controleColuna, passos) || 
          labirinto_bt(labirinto, linha, coluna, controleLinha, controleColuna - 1, passos);
    labirinto[controleLinha][controleColuna] = 0;
    return ans;
}

int main(){
    int linha, coluna, labirinto[20][20];
    scanf("%d %d", &linha, &coluna);
    for (int i = 0; i < linha; ++i)
        for (int j = 0; j < coluna; ++j)
            scanf("%d", &labirinto[i][j]);
    int saida = labirinto_bt(labirinto, linha, coluna, 0, 0, 0);
    printf("%d\n", saida);

    return 0;
}