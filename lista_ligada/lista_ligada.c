#include <stdio.h>
#include <stdlib.h>

// definição do nó
struct ll_node_int {
    int value;
    struct ll_node_int *next;
};

//definição dos ponteiros para o primeiro e ultimo nó
struct ll_int {
    struct ll_node_int *first;
    struct ll_node_int *last;
};

typedef struct ll_int *ll_int;

//inserir elemento no ínicio, recebe struct ll_node_int l e int v
void inserir_inicio(ll_int l, int v){
    //declara ponteiro para novo nó
    struct ll_node_int *new_node;
    
    //o ponteiro recebe o espaço de memoria para novo nó
    new_node = (struct ll_node_int*)malloc(sizeof(struct ll_node_int));
    
    //o elemento value do nó recebe v
    new_node->value = v;
    //o novo nó agora aponta pro primeiro nó
    new_node->next = l->first;

    //se a lista for vazia, então o novo nó agora é também o último
    if(l->first == 0)
        l->last = new_node;
    //o primeiro nó agora é o novo nó
    l->first = new_node;
}

void inserir_fim(ll_int l, int v){
    struct ll_node_int *new_node;
    new_node = (struct ll_node_int*)malloc(sizeof(struct ll_node_int));
    new_node->value = v;
    new_node->next = 0;

    if(l->last==0)
        l->first = new_node;
    else
        l->last->next=new_node;
    
    l->last = new_node;
}

int remover_fim(ll_int l){
    if(l->first == 0)
        return -1;
    int r = l->last->value;
    struct ll_node_int *new_last = l->first;

    while (new_last->next != l->last)
        new_last = new_last->next;
    
    new_last->next = 0;
    free(l->last);
    l->last = new_last;
    return r;
    
}

int remover_inicio(ll_int l){
    if(l->first==0)
        return -1;
    int r = l->first->value;
    struct ll_node_int *old_node = l->first;
    l->first = l->first->next;
    free(old_node);
    
    return r;
    
}

unsigned long long ll_size(ll_int l){
    if(l->first==0)
        return 0;
    struct ll_node_int *current = l->first;
    unsigned long long count = 1;
    while(current != l->last){
        current = current->next;
        count++;
    }
    return count;
}

int ll_inser_after(ll_int l, int value, int existing){
    
    struct ll_node_int *node = (struct ll_node_int*)malloc(sizeof(struct ll_node_int));
    struct ll_node_int *current= l->first;
    int insert = 0;
    while(current != l->last){
        if(current->value == existing){
            node->value = value;
            node->next = current->next;
            current->next = node;
            insert=1;
            break;
        }
        current = current->next;
    }
    if(insert==0)
        inserir_fim(l, value);  
    return 1; 
}

void ll_insert_at(ll_int l, int value, int position){
    struct ll_node_int *node = (struct ll_node_int*)malloc(sizeof(struct ll_node_int));
    struct ll_node_int *current= l->first;
    int index = 0;
    while(current != l->last){
        if(index == position - 1){
            node->value = value;
            node->next = current->next;
            current->next = node;
            break;
        }
        current = current->next;
        index+=1;   
    }
}
void print_list(ll_int l){
   struct ll_node_int *current = l->first;
   printf("{");
   while(current!=0){
    printf("%d ", current->value);
    current = current->next;
   }
   printf("}");
}



int main(){
    ll_int lista = (ll_int)malloc(sizeof(struct ll_int));
    lista->first = 0;
    lista->last = 0;
    inserir_inicio(lista, 10);
    inserir_inicio(lista, 20);
    inserir_inicio(lista, 30);
    inserir_inicio(lista, 40);
    
    print_list(lista);
    printf("Size: %d\n", ll_size(lista));
    ll_inser_after(lista, 100, 30);
    ll_inser_after(lista, 8, 25);
    ll_insert_at(lista, 12, 3);
    print_list(lista);
    // inserir_fim(lista, 80);
    // print_list(lista);
    // remover_fim(lista);
    // print_list(lista);
    // remover_inicio(lista);
    // print_list(lista);
    return 0;
}