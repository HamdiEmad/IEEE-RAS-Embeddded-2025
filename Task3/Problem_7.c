#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    char string[n];
    scanf("%s", string);
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        if (string[i] != string[i + 1]) {
            count++;
        }
    }
    printf("%d\n", count);
}

//https://codeforces.com/group/MWSDmqGsZm/contest/219856/submission/315747613