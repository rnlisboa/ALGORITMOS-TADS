#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);
    
    if (x % 2 == 0) {
        x += 2;
    } else {
        x += 1;
    }
    
    printf("%d\n", x);
    return 0;
}
