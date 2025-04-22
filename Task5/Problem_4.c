#include <stdio.h>

int main() {
    // Matrices input
    short n1, m1, n2, m2;
    scanf("%hd %hd %hd %hd", &n1, &m1, &n2, &m2);
    if (m1 != n2) {
        printf("Invalid Input\n");
        return 0;
    }
    int a[n1][m1], b[n2][m2], c[n1][m2];
    for (short i = 0; i < n1; i++) {
        for (short j = 0; j < m1; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (short i = 0; i < n2; i++) {
        for (short j = 0; j < m2; j++) {
            scanf("%d", &b[i][j]);
        }
    }

    // Matrix multiplication
    int *num1 = a[0], *num2 = b[0];
    for (short i = 0; i < n1; i++) {
        for (short j = 0; j < m2; j++) {
            int *num = &c[i][j];
            *num = 0;
            for (short k = 0; k < m1; k++) {
                *num = *num + *(num1 + i * m1 + k) * *(num2 + k * m2 + j);
            }
        }
    }

    // Resultant matrix
    printf("Product of matrices is:\n");
    for (short i = 0; i < n1; i++) {
        for (short j = 0; j < m2; j++) {
            printf("%d ", c[i][j]);
        }
        printf("\n");
    }
}