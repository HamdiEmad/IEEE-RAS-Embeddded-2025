#include <stdio.h>

int sequence3np1(int n, int count) {
    if (n == 1 && count == 1) return 1;
    if (n == 1 && count != 1) return count;
    else {
        if (n % 2 == 0) {
            count++;
            return sequence3np1(n / 2, count);
        } 
        else {
            count++;
            return sequence3np1(3 * n + 1, count);
        }
    }
}

int main() {
    int num;
    scanf("%d", &num);
    printf("%d\n", sequence3np1(num, 1));
}

//https://codeforces.com/group/MWSDmqGsZm/contest/223339/submission/312306027