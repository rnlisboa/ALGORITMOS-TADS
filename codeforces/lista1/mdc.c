#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return mdc(b, a % b);
    }
}

int main() {
    int a, b;

    scanf("%d %d", &a, &b);

    int resultado = mdc(a, b);
  
    printf("%d\n", resultado);

    return 0;
}


