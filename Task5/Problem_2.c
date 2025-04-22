#include <stdio.h>

void copy(char* a, char* b) {
    while (*a) {
        *b = *a;
        a++;
        b++;
    }
    *b = '\0';
}

int main() {
    char str1[100], str2[100];
    scanf("%s", str1);
    copy(str1, str2);
    printf("Original String: %s\n", str1);
    printf("Copied String: %s\n", str2);
}