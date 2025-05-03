#include <stdio.h>

typedef enum {
    Add = '+',
    Subtract = '-',
    Multiply = '*',
    Divide = '/',
    bitwiseAND = '&',
    bitwiseOR = '|',
    bitwiseNOT = '!',
} operation;

int evaluate(operation op, int a, int b) {
    switch (op) {
        case Add:
            return a + b;
        case Subtract:
            return a - b;
        case Multiply:
            return a * b;
        case Divide:
            return a / b;
        case bitwiseAND:
            return a & b;
        case bitwiseOR:
            return a | b;
        case bitwiseNOT:
            return ~a;
    }
}

int main() {
    printf("Input first number: ");
    int a;
    scanf("%d", &a);
    printf("Input operand: ");
    char op;
    scanf(" %c", &op);
    printf("Input second number: ");
    int b;
    scanf("%d", &b);
    printf("%d %c %d = %d\n", a, op, b, evaluate(op, a, b));
}