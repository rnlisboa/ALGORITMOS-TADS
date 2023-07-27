#include <stdio.h>

struct item{
    double valor;
    int peso;
};

typedef struct item item;

double mochila(item itens[], int n, int capacidade) {
    if (capacidade <= 0 || n == 0)
        return 0;

    double c1 = 0;
    if (itens[n - 1].peso <= capacidade) {
        c1 = itens[n - 1].valor + mochila(itens, n - 1, capacidade - itens[n - 1].peso);
    }

    double c2 = mochila(itens, n - 1, capacidade);

    return c1 > c2 ? c1 : c2;
}

int main() {
    item itens[] = { {8, 4}, {5, 3}, {3, 2}, {12, 6} };
    int n = sizeof(itens) / sizeof(itens[0]);
    int capacidade = 10;

    double valor_maximo = mochila(itens, n, capacidade);
    printf("Valor maximo na mochila: %.2lf\n", valor_maximo);

    return 0;
}