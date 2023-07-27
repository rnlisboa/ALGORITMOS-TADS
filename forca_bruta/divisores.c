#include <stdio.h>
#include <stdlib.h>

// Algoritmo divisores(n)
//      c = 2
//      enquanto (c < n) faça
//          Se (n mod c = 0) então
//              imprima(c)
//          c = c + 1
//      fim enquanto
// fim Algoritmo

void divisores(int n){
    int c = 2;
    while(c < n){
        if(n % c == 0)
            printf("%d\n", c);
        c++;
    }
}

int main(){
    int n;
    scanf("%d", &n);
    divisores(n);
    return 0;
}