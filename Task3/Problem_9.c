#include <stdio.h>

int main() {
    short n;
    scanf("%hd", &n);
    int arr[n];
    for (short i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int min = arr[0];
    for (short i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    short occurences = 0;
    for (short i = 0; i < n; i++) {
        if (arr[i] == min)
            occurences++;
    }
    char *string = occurences % 2 == 0 ? "Unlucky" : "Lucky";
    printf("%s\n", string); 
}

//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/315753694