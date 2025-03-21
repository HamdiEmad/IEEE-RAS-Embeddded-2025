#include <stdio.h>
#include <limits.h>

int main() {
  int largest = INT_MIN;
  int smallest = INT_MAX;
  while (1) {
    int num;
    scanf ("%d", &num);
    if (num == -1) break;
    if (num < smallest) smallest = num;
    if (num > largest) largest = num;
  }
  printf("%d %d\n", largest, smallest);
}