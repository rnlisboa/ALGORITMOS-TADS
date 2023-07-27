#include <stdio.h>
#include <stdlib.h>


int maiorDoArray(int a[], int n){
    int maiorAtual = a[0];
    int i = 0;
    while(i < n){
        if(a[i] > maiorAtual){
            maiorAtual = a[i];
        }
        i++;
    }
    return maiorAtual;
}

int main(){
    int n;
    scanf("%d", &n);
    int a[n];
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);
    printf("%d", maiorDoArray(a, n));
    return 0;
}
