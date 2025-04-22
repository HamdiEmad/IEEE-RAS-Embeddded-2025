#include <stdio.h>
#include <stdlib.h>

int convert(char* str, int size) {
    int digit = 1;
    int num = 0;
    char *number = str + size;
    while (number >= str) {
        if (*number >= '0' && *number <= '9') {
            num += (*number - '0') * digit;
            digit *= 10;
        }
        number--;
    }
    return num;
}

int main() {
    char str[100];
    scanf("%s", str);
    int size = 0;
    char *temp = str;
    while (*temp != '\0') {
        size++;
        temp++;
    }
    printf("%d\n", convert(str, size - 1));
}