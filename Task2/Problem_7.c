#include <stdio.h>

int GCD(int a, int b) {
    if (a == 0 || b == 0) return -1;
    if (a > b && a % b == 0) {
        return b;
    } else if (b > a && b % a == 0) {
        return a;
    } else if (a > b) {
        return GCD(a % b, b);
    } else {
        return GCD(a, b % a);
    }
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", GCD(a, b));
}