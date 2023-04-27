#include <stdio.h>

int main() {
  double a, b;
  scanf("%10lf", &a);
  scanf("%10lf", &b);
  printf("%.5lf", (a + b) / 2);
  return 0;
}
