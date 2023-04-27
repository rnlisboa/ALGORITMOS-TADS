#include <stdio.h>

int main() {
    int inicio, fim, duracao, horas, minutos;
    
    scanf("%d %d", &inicio, &fim);

    duracao = fim - inicio;
    if (duracao < 0) {
        duracao += 1440;
    }

    horas = duracao / 60;
    minutos = duracao % 60;

    printf("%02d:%02d\n", horas, minutos);

    return 0;
}