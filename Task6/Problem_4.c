#include <stdio.h>

struct Cat {
    char *name;
    short age;
    char *food;
    char *kind;
};

int main() {
    struct Cat cat = {"Bassiouni", 3, "cheese", "male"};
    printf("size of Bassiouni is %d\n", sizeof(cat));
}

/*
    The output of the code is 32 bytes as the size of a struct is the sum of the sizes
    of its members (name := 8 bytes, age = 2 bytes, food = 8 bytes, kind = 8 bytes and
    6 bytes for the padding so that the next char* pointer starts at an 8-byte
     aligned address.).
*/ 