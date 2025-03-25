#include <stdio.h>
#include <math.h>

void reach(long long n) {
    if (n == 1) {
        printf("YES\n");
        return;
    }
    if (n % 20 == 0 && ((int)log10(n) != log10(n))) {
        reach(n / 20);
        return;
    }
    if (n % 10 == 0) {
        reach(n / 10);
        return;
    }
    else {
        printf("NO\n");
        return;
    } 
}

int main() {
    short t; 
    scanf("%hd", &t);
    for (short i = 0; i < t; i++) {
        long long n;
        scanf("%lld", &n);
        reach(n);
    }
}

//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312309056