#include <stdio.h>
#include "operations.c"

int main() {
    operands op = {2, 4};
    printf("Addition: %d\n", add(op.a, op.b));
    printf("Subtraction: %d\n", subtract(op.a, op.b));
    printf("Multiplication: %d\n", multiply(op.a, op.b));
    printf("Division: %d\n", divide(op.a, op.b));
    printf("Exponent: %d\n", exponent(op.a, op.b));
}