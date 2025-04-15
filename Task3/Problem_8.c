#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    int words = 0;
    char string[1000000];
    fgets(string, sizeof(string), stdin);
    for (int i = 0; i < strlen(string); i++) {
        if (isalpha(string[i]) && !isalpha(string[i + 1]))
            words++; 
    }
    printf("%d\n", words);
}

//https://codeforces.com/group/MWSDmqGsZm/contest/219856/submission/315751651