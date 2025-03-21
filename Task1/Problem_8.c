#include <stdio.h>

int main() {
    int n, sum;
    scanf("%d", &n);
    int i = 1;
    while (i < n) {
        if (n % i == 0) {
            sum += i;
        }
        i++;
    }
    if (sum == n)
        printf("%d is a perfect number", n);
    else 
        printf("%d is not a perfect number", n);
}