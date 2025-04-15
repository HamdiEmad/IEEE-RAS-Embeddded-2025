#include <stdio.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);
    bool cond = true;
    int rowSum = 0, colSum = 0, secondaryDiagonalSum = 0, mainDiagonalSum = 0;
    for (int i = 0; i < n; i++) {
        mainDiagonalSum += arr[i][i];
        secondaryDiagonalSum += arr[i][n - i - 1];
    }
    if (mainDiagonalSum != secondaryDiagonalSum)
        cond = false;
    for (int i = 0; i < n; i++) {
        rowSum = colSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += arr[i][j];
            colSum += arr[j][i];
        }
        if (rowSum != mainDiagonalSum || colSum != mainDiagonalSum)
            cond = false;
    }
    char *string = cond ? "The square is a magic square. " : "The square is not a magic square.";
    printf("%s", string);
}