#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char *string;
    scanf("%m[^\n]", &string);
    bool cond = true;
    int length = strlen(string);
    for (int i = 0; i < length / 2; i++) {
        if (string[i] != string[length - i - 1]) {
            cond = false;
            break;
        }
    }
    if (cond) {
        printf("The word '%s' is a palindrome.", string);
    }
    else {
        printf("The word '%s' is not a palindrome.", string);
    }
    free(string);
<<<<<<< HEAD
}
=======
}
>>>>>>> dbd5e62 (Save local changes before pull)
