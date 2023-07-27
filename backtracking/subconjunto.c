#include <stdio.h>

// Dado um conjunto de números inteiros e um valor alvo, 
// escreva um programa para encontrar todos os subconjuntos do conjunto que 
// somem o valor alvo.

void soma_bt(int a[], int n, int s) {
    for(int i=0; i < n; ++i){
       
        for(int j=i + 1; j < n; ++j){
            if(a[i] + a[j] == s)
                printf("%d %d", a[i], a[j]);
        }
    }
}


int main(){
    int n, s;
    scanf("%d", &n);
    scanf("%d", &s);
    int a[n];

    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    
    soma_bt(a, n, s);

    return 0;
}