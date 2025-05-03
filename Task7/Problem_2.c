#include <stdio.h>

typedef int integer;
typedef char character;
typedef float floated_number;
typedef double huge_floated_number;
typedef unsigned int unsigned_integer;
typedef char* string;
typedef short short_integer;
typedef long long_integer;

int main() {
    printf("Size of integer : %zu bytes\n", sizeof(integer));
    printf("Size of character : %zu bytes\n", sizeof(character));
    printf("Size of floated_number : %zu bytes\n", sizeof(floated_number));
    printf("Size of huge_floated_number : %zu bytes\n", sizeof(huge_floated_number));
    printf("Size of unsigned_integer : %zu bytes\n", sizeof(unsigned_integer));
    printf("Size of string : %zu bytes\n", sizeof(string));
    printf("Size of short_integer : %zu bytes\n", sizeof(short_integer));
    printf("Size of long_integer : %zu bytes\n", sizeof(long_integer));
}