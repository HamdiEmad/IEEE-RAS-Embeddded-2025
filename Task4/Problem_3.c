#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1 = 10;
    int num2 = 20;
    printf("%d %d\n", num1, num2);
    swap(&num1, &num2);
    printf("%d %d\n", num1, num2);
}