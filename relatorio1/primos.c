#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int limite = 500000;
    clock_t start_time, end_time;
    double tempo;

    start_time = clock();
    for (int i = 1; i < limite; i++) {
        if (is_prime(i)) {
            printf("%d\n", i);
        }
    }
    end_time = clock();

    tempo = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.2f segundos\n", tempo);

    return 0;
}
