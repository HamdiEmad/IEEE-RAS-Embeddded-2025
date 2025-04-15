#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int mainDiagonal = 0;
    int diagonalSum = 0;
    for (int i = 0; i < n; i++) {
        mainDiagonal += arr[i][i];
        diagonalSum += arr[i][n - i - 1];
    }
    int result = abs(mainDiagonal - diagonalSum);
    printf("%d\n", result);
}

//https://codeforces.com/group/MWSDmqGsZm/contest/219774/submission/315731147