#include <stdio.h>
#include <time.h>
#include "array_list_int.h"
#include "array_list_int.c"

void error_at_insertion(array_list_int* l, int x) {
  fprintf(stderr, "\033[0;31mErro:\033[0m:\tValor %d não inserido!\n", x);
  fprintf(stderr, "\tA lista possui %d elementos.\n", array_list_size(l));
  exit(1);
}


void print_vector(array_list_int* l) {
  int i, x, erro;
  for (i = 0; i < array_list_size(l); ++i) {
    x = array_list_get(l, i, &erro);
    if (!erro) {
      printf("%d ", x);
    } else {
      fprintf(stderr, "ERRO: índice %d não é válido!\n", i);
      exit(2);
    }
  }
  printf("\n");
}

int main() {
  time_t inicio, fim;
  int n, i, x, indice, valor;
  array_list_int* l01 = array_list_create();

  scanf("%d", &n);

  inicio = time(0);
  for (i = 0; i < n; ++i) {
    scanf("%d", &x);
    if (array_list_push_back(l01, x) != (i + 1)) {
      error_at_insertion(l01, x);
    }
  }
  fim = time(0);
  fprintf(stderr, "Inserção de %d elementos em %.16lf milissegundos.\n", n,
          (((double)fim - (double)inicio) / (CLOCKS_PER_SEC * 1000)));

  printf("Tamanho do vetor: %d\n", array_list_size(l01));

  printf("Digite o indice que deseja saber o elemento: ");
  scanf("%d", &indice);
  int error = 0;
  inicio = time(0);
  valor = array_list_get(l01, indice, &error);
  fim = time(0);
  if (error) {
    fprintf(stderr, "Erro ao obter o elemento no índice %d.\n", indice);
  } else {
    printf("Valor do elemento no índice %d: %d em %.16lf milissegundos\n", indice, valor, (((double)fim - (double)inicio) / (CLOCKS_PER_SEC * 1000)));
  }

  int indice_rm;
  printf("Digite o indice que deseja remover o elemento: ");
  scanf("%d", &indice_rm);

  inicio = time(0);
  array_list_remove_from(l01, indice_rm);
  fim = time(0);
  fprintf(stderr, "Elemento de indice %d removido em %.16lf milissegundos.\n", indice_rm,
          (((double)fim - (double)inicio) / (CLOCKS_PER_SEC * 1000)));

  printf("Capacidade da lista: %d\n", array_list_capacity(l01));

  // Teste de busca de elemento
  int elem_busca;
  printf("Digite o elemento a ser buscado: ");
  scanf("%d", &elem_busca);
  inicio = time(0);
  int indice_encontrado = array_list_find(l01, elem_busca);
  fim = time(0);
  printf("Elemento %d encontrado no índice %d em %.16lf milissegundos.\n", elem_busca, indice_encontrado, (((double)fim - (double)inicio) / (CLOCKS_PER_SEC * 1000)));
  // Teste de inserção
  int indice_insert;
  printf("Digite o indice que deseja inserir o elemento: ");
  scanf("%d", &indice_insert);
  int value_insert;
  printf("Digite o valor que deseja inserir o elemento: ");
  scanf("%d", &value_insert);
  inicio = time(0);
  array_list_insert_at(l01, indice_insert, value_insert);
  fim = time(0);
  printf("Elemento %d inserido no índice %d em %.16lf milissegundos.\n", value_insert, indice_insert, (((double)fim - (double)inicio) / (CLOCKS_PER_SEC * 1000)));
  
  inicio = time(0);
  array_list_pop_back(l01);
  fim = time(0);
  printf("função pop executada em %.16lf milissegundos.\n", (((double)fim - (double)inicio) / (CLOCKS_PER_SEC * 1000)));
  

  printf("Porcentagem de ocupação da lista: %.2lf%%\n", array_list_percent_occupied(l01));

  array_list_destroy(l01);
  return 0;
}
