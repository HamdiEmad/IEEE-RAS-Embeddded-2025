#include <stdio.h>

struct Cat {
    char *name;
    short age;
    char *food;
    char *kind;
};

struct Cat create_cat(char *name, short age, char *food, char *kind) {
    struct Cat cat;
    cat.name = name;
    cat.age = age;
    cat.food = food;
    cat.kind = kind;
    return cat;
}

int main() {
    struct Cat cat = create_cat("Milo", 3, "Meat", "male");
    printf("Name: %s\n", cat.name);
    printf("Age: %d\n", cat.age);
    printf("Food: %s\n", cat.food);    
    printf("Kind: %s\n", cat.kind);
}