#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isArmstrong(int n);

int main() {
  for (int i = 1; i < 1000; i++) {
    if (isArmstrong(i)) printf("%d ", i);
  }
}

bool isArmstrong(int n) {
  int sum = 0, temp = n;
  while(n) {
    sum += (int)pow((n % 10), 3);
    n /= 10;
  }
  return sum == temp;
}