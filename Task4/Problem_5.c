#include <stdio.h>

int length(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int main() {
    char str[] = "Empedded Systems";
    printf("Length = %d\n", length(str));
}