#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    
    int numeros[n];
    double soma = 0.0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &numeros[i]);
        soma += numeros[i];
    }

    double media = soma / n;
    printf("%.1f\n", media);

    int abaixo_da_media = 0;
    int acima_ou_igual_a_media = 0;
    for (int i = 0; i < n; i++) {
        if (numeros[i] < media) {
            abaixo_da_media++;
        } else {
            acima_ou_igual_a_media++;
        }
    }

    printf("%d", abaixo_da_media);
    for (int i = 0; i < n; i++) {
        if (numeros[i] < media) {
            printf(" %d", numeros[i]);
        }
    }
    printf("\n");

    printf("%d", acima_ou_igual_a_media);
    for (int i = 0; i < n; i++) {
        if (numeros[i] >= media) {
            printf(" %d", numeros[i]);
        }
    }

    return 0;
}
