#include <stdio.h>

int main() {
    int m1, n1, m2, n2;
    scanf("%d %d %d %d", &m1, &n1, &m2, &n2);
    int arr1[m1][n1];
    int arr2[m2][n2];
    if (m1 != m2 || n1 != n2) {
        printf("Error: Matrices are not the same size.\n");
        return 1;
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            scanf("%d", &arr1[i][j]);
        }
    }
    for (int i = 0; i < m2; i++) {
        for (int j = 0; j < n2; j++) {
            scanf("%d", &arr2[i][j]);
        }
    }
    int result[m1][n1];
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            result[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    for (int i = 0; i < m1; i++) {
        for (int j = 0; j < n1; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
}