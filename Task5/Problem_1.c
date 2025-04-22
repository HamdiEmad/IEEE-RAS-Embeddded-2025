#include <stdio.h>
#include <stdlib.h>

short compare(char* a, char* b) {
    while (*a && *b) {
        if (*a != *b)
            return 0;
        a++;
        b++;
    }
    return (*a == *b);
}

int main() {
    char str1[100], str2[100];
    scanf("%s", str1);
    scanf("%s", str2);
    if (compare(str1, str2)) {
        printf("Both strings are Identical\n");
    }
    else {
        printf("Both strings are not Identical\n");
    }
}