#include <stdio.h>

// 1 1 2 3 5 8 13 21 34 55

int fibonacci(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", fibonacci(n));
}

//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312303132