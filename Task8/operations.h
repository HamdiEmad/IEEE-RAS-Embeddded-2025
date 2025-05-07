#pragma once
#define OPERATIONS_H    

typedef struct {
    int a;
    int b;
} operands;

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int exponent(int a, int b);
