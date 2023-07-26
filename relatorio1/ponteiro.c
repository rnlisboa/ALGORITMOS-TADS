#include <stdio.h>

void swap(int* a, int* b){
    int *p = 0;
    printf("%d %d\n", *a, *b);
    p = a;
    a = b;
    b = p;
    printf("%d %d", *a, *b);
}

int main() {
    int x = 10;
    int y = 20;
    swap(&x, &y);

    return 0;
}

