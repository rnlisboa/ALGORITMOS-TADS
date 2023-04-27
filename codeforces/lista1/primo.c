#include <stdio.h>

int main() {
    int x;
    int numDiv = 0;
    int counter = 1;
    scanf("%d", &x);
    while(counter <= x){
      int resto = x % counter;
      if (resto == 0){
        numDiv += 1;
      }
      counter += 1;
    }
    
    if (x == 2){
      printf("%s", "Sim");
    } else if (numDiv > 2 || x == 1){
      printf("%s", "Nao");
    } else{
      printf("%s", "Sim");
    }
  
    return 0;
}
