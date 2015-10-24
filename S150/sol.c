#include <stdio.h>

int main() {
  
  int i, j, n;
  
  while (scanf("%d", &n) != EOF) {
  
    for (i = 0; i < n; i++) {
  
      for (j = i * i; j > 0; j -= i) {
        printf("%d ", j + 1);
      }
  
      printf("1\n");
    }
  
    
  }
  
  return 0;
  
}