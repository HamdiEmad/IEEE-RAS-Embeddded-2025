#include <stdio.h>

void evenNumber(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] % 2 == 0) {
            printf("%c", str[i]);
        }
        i++;
    }
}

int main() {
    char str[] = "012345678";
    evenNumber(str);
    printf("\n");
}