#include <stdio.h>

int main() {
    int num1;
    int num2;
    scanf("%d %d", &num1, &num2);
    int *ptr1 = &num1;
    int *ptr2 = &num2;
    printf("Sum = %d\n", *ptr1 + *ptr2);
    printf("Difference = %d\n", *ptr1 - *ptr2);
    printf("Product = %d\n", *ptr1 * *ptr2);
    printf("Quotient = %d\n", *ptr1 / *ptr2);
}