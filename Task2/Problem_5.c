#include <stdio.h>

void digits(long long n) {
    if (n < 10) { 
        printf("%lld", n);
        return;
    }
    digits(n / 10);
    printf(" %lld", n % 10);
}

int main() {
    short t;
    scanf("%hd", &t);
    for (short i = 0; i < t; i++) {
        long long n;
        scanf("%lld", &n);
        if (n == 0) 
            printf("0");
        else
            digits(n);
        printf("\n"); 
    }
    return 0;
}

//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312302642