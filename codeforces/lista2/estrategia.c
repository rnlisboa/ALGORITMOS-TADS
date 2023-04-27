#include <stdio.h>

int main(void) {
  int j, r, i = 0;
  scanf("%d %d", &j, &r);
  int jogadas[r*j];
  for (i = 0; i < r * j; i++) {
    int jogada;
    scanf("%d", &jogada);
    jogadas[i] = jogada;
  }

  int pontos[j], mais_pontos = 0, vencedor = 0;
  
  for (i = 0; i < r * j; i++) {
    pontos[(i % j)] += jogadas[i];
  }

  for (i = 0; i < j; i++) {
    if (i == 0 || pontos[i] > mais_pontos) {
      mais_pontos = pontos[i];
      vencedor = i + 1;
    }
  }
  
  printf("%d\n", vencedor);
  return 0;
}
