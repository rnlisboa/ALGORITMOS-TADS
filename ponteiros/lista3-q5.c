#include <stdio.h>
#include <stdlib.h>

struct array_list {
    int *data;
    unsigned int size;
    unsigned int capacity;
};

void array_list_increase_capacity(struct array_list *list) {
    list->capacity += 10;
    int *new_data = (int*)realloc(list->data, sizeof(int) * list->capacity);
    if (new_data == NULL) {
        fprintf(stderr, "Error on memory allocation.\n");
        exit(-1);
    }
    list->data = new_data;
}

struct array_list * array_list_create() {
    struct array_list *new_list;
    new_list = (struct array_list*)malloc(sizeof(struct array_list));
    if (new_list == NULL) {
        fprintf(stderr, "Error on memory allocation.\n");
        exit(-1);
    }
    new_list->capacity = 10;
    new_list->size = 0;
    new_list->data = (int*)malloc(sizeof(int) * new_list->capacity);
    if (new_list->data == NULL) {
        fprintf(stderr, "Error on memory allocation.\n");
        exit(-1);
    }
    return new_list;
}

void array_list_read_until(struct array_list *list, int end_reading) {
    int x;
    while (scanf("%d", &x), x != end_reading) {
        if (list->size == list->capacity)
            array_list_increase_capacity(list);
        list->data[list->size++] = x;
    }
}

void array_list_print(struct array_list *list) {
    printf("[");
    if (list->size > 0) {
        printf("%d", list->data[0]);
        for (int i = 1; i < list->size; ++i)
            printf(", %d", list->data[i]);
    }
    printf("]");
}

int main() {
    struct array_list *list01 = array_list_create();
    array_list_read_until(list01, -1);
    array_list_print(list01);
    printf("\n");
    free(list01->data);
    free(list01);
    return 0;
}