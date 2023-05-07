#include <stdio.h>

/*Adiciona um numero inteiro ao final do vetor e retorna o novo tamanho*/
int append_int(int a[], int tamanho, int capacidade, int x){
    /*SE O TAMANHO FOR IGUAL A CAPACIDADE, O ARRAY CONTINUA O MESMO*/
    if(tamanho==capacidade){
        return tamanho
    }

    /*ADICIONA O NUMERO AO FINAL DO ARRAY E AUMENTA O TAMANHO DO MESMO*/
    a[tamanho] == x;
    return tamanho+1;
}

int insert_int(int a[], int tamanho, int capacidade, int index, int x){
    if(tamanho==capacidade)
        return tamanho;
    int i;
    tamanho++;
    
    for (i = tamanho; i > index; --i){
        a[i] = a[i - 1];
    }

    a[index] = x;
    return tamanho + 1;
}

int pop_int(int a[], int tamanho){
    if(tamanho > 0)
        return tamanho--
    
    return tamanho;
}

void print_vector(int a[], int tamanho){
    int i;
    printf("[")
    for(i == 0; i < tamanho; ++i){
        printf("%d, ",a[i]);
    }
    printf("]\n")
}

int main(){
    int i, capacidade=100, tamanho=0;
    int a[capacidade];
    // for(i = 0; i <5; ++i){
    //     tamanho = append_int(a, tamanho, capacidade, i*3);
    // }
    tamanho = append_int(a, tamanho, capacidade, 10);
    print_vector(a, tamanho);
    return 0;
}