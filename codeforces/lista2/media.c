#include <stdio.h>

int main() {
    int n;
    long long abaixo, count = 0;
    long long acima = 0;
    double media;
    int igual = 0;
    scanf("%d", &n);
    
    int lista[n];
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        lista[i] = x;
        count += x;
    }
    media = count / (double)n;
    
    for(int i = 0; i < n; i++){
      if(lista[i] >= media){
        acima = acima + 1;
      }
    }
    abaixo = n - acima;
  
    printf("%.1f\n", media);
    printf("%lld\n", abaixo); 
    printf("%lld\n", acima);
  
    return 0;
}
