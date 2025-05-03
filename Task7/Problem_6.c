#include <stdio.h>

union storage {
    int a;
    float b;
    char c;
};

int main() {
    union storage data = {.a = 65};
    printf("Integer: %d\n", data.a);
    printf("Floated number: %f\n", data.b);
    printf("Character: %c\n", data.c);

    data.b = 80;
    printf("Integer: %d\n", data.a);
    printf("Floated number: %f\n", data.b);
    printf("Character: %c\n", data.c);

    data.c = 'H';
    printf("Integer: %d\n", data.a);
    printf("Floated number: %f\n", data.b);
    printf("Character: %c\n", data.c);

    /*
    The output of the program will be unpredictable because the union shares the same memory location for all its members. 
    When you assign a value to one member, it may affect the values of the other members.
    */
}