#include <stdio.h>

int add(int num1, int num2) {
    return num1 + num2;
}

int subtract(int num1, int num2) {
    return num1 - num2;
}

int multiply(int num1, int num2) {
    return num1 * num2;
}

int divide(int num1, int num2) {
    if (num2 == 0) {
        printf("Error: Division by zero is not allowed.\n");
        return -1;
    }
    return num1 / num2;
}

int main() {
    int (*operation)(int, int) = NULL;
    printf("Select an operation:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
    printf("Enter your choice: ");
    short choice;
    scanf("%hd", &choice);
    printf("Enter two numbers: ");
    int num1, num2;
    scanf("%d %d", &num1, &num2);
    switch (choice) {
        case 1:
            operation = add;
            break;
        case 2:
            operation = subtract;
            break;
        case 3:
            operation = multiply;
            break;
        case 4:
            operation = divide;
            break;
    }
    printf("Result: %d", operation(num1, num2));
}