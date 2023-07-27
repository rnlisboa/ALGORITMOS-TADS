#include <stdio.h>

int bt(int n){
    if (n == 0) return 1;
    printf("%d\n", n);
    return n+bt(n-1);
}

int main(){
    printf("%d", bt(10));
    return 0;
}