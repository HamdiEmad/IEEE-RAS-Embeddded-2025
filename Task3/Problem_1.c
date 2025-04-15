#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    long long arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &arr[i]);
    }
    long long num;
    scanf("%lld", &num);
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            printf("%d", i);
            return 0;
        }
    }
    printf("-1");
}

//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/315726741