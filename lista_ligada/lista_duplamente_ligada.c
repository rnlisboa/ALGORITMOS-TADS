#include <stdio.h>
#include <stdlib.h>

struct ll_node_int {
    int value;
    struct ll_node_int *prox, *prev;
};

struct ll_int {
    struct ll_node_int *head, *tail;
};

typedef struct ll_int *ll_int;

void inserir_inicio(ll_int list, int v){
    //cria novo no
    struct ll_node_int *new_node;
    new_node = (struct ll_node_int*)malloc(sizeof(struct ll_node_int));
    new_node->value = v;
    new_node->prox = 0;
    new_node->prev = 0;
    if(list->head == 0)
        list->tail = new_node;
    else
        list->head->prev= new_node;
    new_node->prox = list->head;
    list->head = new_node;
}

void inserir_fim(ll_int list, int v){
    struct ll_node_int *new_node;
    new_node = (struct ll_node_int*)malloc(sizeof(struct ll_node_int));
    new_node->value = v;
    new_node->prev = 0;
    new_node->prox = 0;
    if(list->tail == 0)
        list->head = new_node;
    else
        list->tail->prox = new_node;
    new_node->prev = list->tail;
    list->tail = new_node;

}

void remove_fim(ll_int list){
    struct ll_node_int *new_last = (struct ll_node_int*)malloc(sizeof(struct ll_node_int));
    new_last = list->tail->prev;
    new_last->prox = 0;
    free(list->tail);
    list->tail = new_last;
}

void remove_inicio(ll_int list){
    struct ll_node_int *new_first = (struct ll_node_int*)malloc(sizeof(struct ll_node_int));
    new_first->prev = 0;
    new_first = list->head->prox;
    free(list->head);
    list->head = new_first;
}

void insert_at(ll_int list, int value, int index){
    struct ll_node_int *current = list->head;
    struct ll_node_int *new_node = (struct ll_node_int*)malloc(sizeof(struct ll_node_int));
    new_node->value = value;
    int n_index = 0;
    while (current != list->tail){
        if(n_index == index-1){
            new_node->prev = current;
            new_node->prox = current->prox;
            current->prox = new_node;
            break;
        }
        current = current->prox;
        n_index+=1;
    }
    
}

void print(ll_int l){
    struct ll_node_int *current;
    current = l->head;
    printf("{");
    
    while(current != 0){
        printf(" %d ", current->value);
        current = current->prox;
    }

    printf("}");
}

int main(){
    struct ll_int *list = (struct ll_int*)malloc(sizeof(struct ll_int));
    list->head = 0;
    list->tail = 0;
    inserir_inicio(list, 10);
    inserir_inicio(list, 20);
    inserir_inicio(list, 30);
    inserir_inicio(list, 40);
    inserir_fim(list, 35);
    print(list);
    insert_at(list, 22, 2);
    print(list);
    return 0;
}