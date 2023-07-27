#include "array_list_int.h"
#include <stdio.h>
#include <stdlib.h>


struct array_list_int {
  int* data;
  unsigned int size, capacity;
};


int increase_memory(struct array_list_int *list) {
    // calcula a nova capacidade
    unsigned int new_capacity = list->capacity * 2;
    // aloca uma nova região de memória com a nova capacidade
    int* new_data = (int*)malloc(sizeof(int) * new_capacity);
    if (new_data == 0) 
        return 0;
    // copia os elementos da lista original para a nova região de memória
    for (unsigned int i = 0; i < list->size; i++)
        new_data[i] = list->data[i];
    // libera a memória da lista original
    free(list->data);
    // atualiza os campos da estrutura para refletir a nova capacidade e dados
    list->data = new_data;
    list->capacity = new_capacity;
    // retorna 1 indicando que a capacidade foi aumentada com sucesso
    return 1;
}

array_list_int* array_list_create() {
    array_list_int* new_list = (array_list_int*)malloc(sizeof(array_list_int));
    if (new_list == NULL) {
        fprintf(stderr, "Error on memory allocation.\n");
        exit(-1);
    }

    new_list->data = (int*)malloc(sizeof(int) * 8);
    if (new_list->data == NULL) {
        fprintf(stderr, "Error on memory allocation.\n");
        exit(-1);
    }

    new_list->size = 0;
    new_list->capacity = 8;
    return new_list;
}

int array_list_get(array_list_int* list, int index, int* error) {
  *error = 0;
  if (index < 0 || index >= list->size) {
    *error = 1;
    return 0;
  }
  return list->data[index];
}

unsigned int array_list_push_back(array_list_int* list, int value) {
  if (list->capacity == list->size) {
    if (!increase_memory(list)) /* Precisa aumentar a memória */
      return array_list_size(list);
  }
  list->data[list->size] = value;
  list->size++;
  return array_list_size(list);
}

/**/
unsigned int array_list_pop_back(array_list_int* list) {
  if(list->size > 0) // se o tamanho da lista for maior que zero, decrementa o tamanho
    list->size--;
  return array_list_size(list);
}

/**/
unsigned int array_list_size(array_list_int* list) {
  return list->size;
}

/**/
int array_list_find(array_list_int* list, int element) {
  for(unsigned int i = 0; i < list->size; ++i)
    if(list->data[i] == element)
      return i;
  return -1;
}

/**/
unsigned int array_list_insert_at(array_list_int* list, int index, int value) {
  if(index >= 0 && index <= list->size){ //se o índice for válido
    if(list->size >= list->capacity)
      increase_memory(list);
  }
  /* percorre do maior índice até o ídice passado no parâmetro e move cada elemento para o índice sucessor */
  for(int i = list->size - 1; i>=index; --i){
    list->data[i+1] = list->data[i];
  }
  // insere o valor no índice passado
  list->data[index] = value;
  //incrementa o tamanho da lista
  list->size++;
  return array_list_size(list);
}

/**/
unsigned int array_list_remove_from(array_list_int* list, int index) {
  if(index >= 0 && index < list->size){//se o índice for válido
    for(unsigned int i = index + 1; i < list->size; ++i){ /* percorre de a lista de forma 
    decrescente atribuindo cada valor para o antecessor até o índice passado*/
      list->data[i - 1] = list->data[i];
    }
    list->size--; //decrementa o tamanho da lista
  }
  return array_list_size(list);
}

unsigned int array_list_capacity(array_list_int* list) {
  return list->capacity;
}

double array_list_percent_occupied(array_list_int* list) {
  if (list->capacity == 0)
    return 0.0;
  return ((double)list->size / list->capacity) * 100;
}


void array_list_destroy(array_list_int* list) {
  free(list->data);
  free(list);
}

