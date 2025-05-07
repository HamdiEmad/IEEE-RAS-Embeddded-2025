#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    printf("Enter the number of bytes to allocate: ");
    scanf("%d", &num);

    int sum = 0;
    int *ptr = (int*)malloc(num * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < num; i++) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }

    printf("Sum of the numbers: %d\n", sum);
    free(ptr);
}