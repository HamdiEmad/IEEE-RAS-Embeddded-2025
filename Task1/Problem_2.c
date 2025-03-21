#include <stdio.h>
 
int main() {
    int age;
    scanf("%d", &age);
    printf("%d years\n%d months\n%d days", age / 365, age % 365 / 30, age % 365 % 30);
}

//https://codeforces.com/group/MWSDmqGsZm/contest/219158/submission/311600180