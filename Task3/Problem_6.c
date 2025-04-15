#include <stdio.h>

int main() {
    short n, m;
    scanf("%hd %hd", &n, &m);
    long long arr[n][m];
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < m; j++) {
            scanf("%lld", &arr[i][j]);
        }
    }
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < m / 2; j++) {
            long long temp = arr[i][j];
            arr[i][j] = arr[i][m - j - 1];
            arr[i][m - j - 1] = temp;
        }
    }
    for (short i = 0; i < n; i++) {
        for (short j = 0; j < m; j++) {
            printf("%lld ", arr[i][j]);
        }
        printf("\n");
    }
}

//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/315731147