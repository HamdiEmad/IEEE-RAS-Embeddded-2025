#include <stdio.h>

int main() {
    signed int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d\n", i);
        }
    }
}

//https://codeforces.com/group/MWSDmqGsZm/contest/219432/submission/311601477