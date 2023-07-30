#include "ordenacao.h"

/* TODO: Implementar função */
int ordenado(int a[], int t){
    for (int i = 0; i < t - 1; ++i)
    {
        if (a[i] > a[i + 1])
            return 0;
    }
    return 1;
}

/* TODO: Implementar função */
void selecao(int a[], int t){
    int i, j, min, aux; // declara indicies, valor minimo e auxiliar
    for (i = 0; i < (t - 1); i++){ //percorre o vetor
    
        min = i; 
        for (j = i + 1; j < t; j++){//percorre novamente o vetor
            //verfica se o valor é menor que o minimo atual, 
            //se sim, minimo recebe este valor
            if (a[j] < a[min])
                min = j;
        }
        // se o elemento atual for diferente do menor elemento encontrado 'a[min]'
        // faz a troca dos elementos 'a[i]' e 'a[min]
        if (a[i] != a[min]){
            aux = a[i];
            a[i] = a[min];
            a[min] = aux;
        }
    }
}

/* TODO: Implementar função */
void insercao(int a[], int t){
    int i, j, atual;
    for (i = 1; i < t; ++i)
    {
        atual = a[i];
        j = i - 1;

        while (j >= 0 && a[j] > atual)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = atual;
    }
}

void merge(int a[], int i1, int j1, int i2, int j2) {
    int *temp = (int *)malloc(sizeof(int) * ((j1 - i1) + (j2 - i2) + 2));

    if (temp == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(EXIT_FAILURE);
    }

    int i = i1, j = i2, k = 0;

    while (i <= j1 && j <= j2) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= j1)
        temp[k++] = a[i++];

    while (j <= j2)
        temp[k++] = a[j++];

    for (i = i1, j = 0; i <= j2; i++, j++)
        a[i] = temp[j];
 
    free(temp);
}

void merge_sort(int a[], int primeiro, int ultimo) {
    if (primeiro < ultimo) {
        int meio = (primeiro + ultimo) / 2;
        merge_sort(a, primeiro, meio);
        merge_sort(a, meio + 1, ultimo);
        merge(a, primeiro, meio, meio + 1, ultimo);
    }
}
