#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n);

int main() {
    int n, sum = 0;
    scanf("%d", &n);
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    if (isPrime(sum))
        printf("The sum of digits (%d) is a prime number.", sum);
    else 
        printf("The sum of digits (%d) is not a prime number.", sum);
}

bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0 && i != n) {
            return false;
        }
    }
    return true;
}