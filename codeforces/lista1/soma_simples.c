#include <stdio.h>

int soma(int a, int b){
  
  if(a >= 1000 ||  a <= -1000 || b >= 1000 ||  b <= -1000){
    printf("os parametros devem estar entre -1000 e 1000");
    return 0;
  }
  return a + b;
}

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);

  printf("%d", soma(a, b));
  return 0;
}