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

void insert(ll_int list, int value){
    struct ll_node_int *new_node = (struct ll_node_int*)malloc(sizeof(struct ll_node_int));
    struct ll_node_int *current = list->head;
    new_node->value = value;
    
    if (new_node->value < current->value) {
        new_node->prox = current;
        new_node->prev = NULL;
        current->prev = new_node;
        list->head = new_node;
        return;
    }

    while (current != NULL) {
        if (new_node->value <= current->value) {
            new_node->prox = current;
            new_node->prev = current->prev;
            if (current->prev != NULL) {
                current->prev->prox = new_node;
            }
            current->prev = new_node;
            return;
        }
        current = current->prox;
    }

    // Caso em que o novo nó tem o maior valor da lista
    new_node->prox = NULL;
    new_node->prev = list->tail;
    list->tail->prox = new_node;
    list->tail = new_node;
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
    for(int i = 10; i <= 100; i = i + 10){
        inserir_fim(list, i);
    }
    print(list);
    printf("\n");
    int n;
    while(n !=0){
        scanf("%d", &n);
        insert(list, n);
        print(list);
        printf("\n");
    }
    
    
    return 0;
}