#include <stdio.h>
 
int main() {
    long long a, b, c, d;          
    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
    a %= 100,b %= 100,c %= 100,d %= 100;
    int x = a * b * c * d;
    if(x % 100 <= 9) printf("0");
    printf("%d", x % 100);
}

//https://codeforces.com/group/MWSDmqGsZm/contest/219158/submission/311600371