#include <stdio.h>

void divisible(int a, int b);

int main() {
  int a, b;
  scanf("%d %d", &a, &b);
  divisible(a, b);
}

void divisible(int a, int b) {
  if (b == 0) {
    printf("Division by zero\n");
    return;
  }
    if (a % b == 0) 
        printf("%d is divisible by %d\n", a, b);
    else
        printf("%d is not divisible by %d\n", a, b);
}