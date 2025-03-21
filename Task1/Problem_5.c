#include <stdio.h>

int main() {
    while (1) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (a <= 0 || b <= 0) 
            break;
        int smaller, larger;
        if (a > b) {
            smaller = b;
            larger = a;
        }
        else {
            smaller = a;
            larger = b;
        }
        int sum = 0;
        for (int i = smaller; i <= larger; i++) {
            printf("%d ", i);
            sum += i;
        }
        printf("sum =%d\n", sum);
    }
}

//https://codeforces.com/group/MWSDmqGsZm/contest/219432/submission/311601373