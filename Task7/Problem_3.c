#include <stdio.h>

typedef struct number {
    int real;
    int imaginary;
} complex;

complex add(complex a, complex b) {
    complex result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
};

int main() {
    complex a = {3, 4};
    complex b = {5, 6};
    complex c = add(a, b);
    printf("Sum of complex numbers: %d + %di\n", c.real, c.imaginary);}