#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr = (int*)malloc(4 * sizeof(int));
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        *(ptr + i) = i;
    }
    for (int i = 0; i < 4; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");
    
    int *ptr2 = calloc(4, sizeof(int));
    if (ptr2 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        *(ptr2 + i) = i * 3;
    }
    for (int i = 0; i < 4; i++) {
        printf("%d ", *(ptr2 + i));
    }
    printf("\n");

    int *ptr3 = malloc(4 * sizeof(int));
    if (ptr3 == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    for (int i = 0; i < 4; i++) {
        *(ptr3 + i) = i * 2;
    }
    for (int i = 0; i < 4; i++) {
        printf("%d ", *(ptr3 + i));
    }
    printf("\n");
    
    int *ptr4 = realloc(ptr2, 8 * sizeof(int));
    if (ptr4 == NULL) {
        printf("Memory reallocation failed\n");
        return 1;
    }
    ptr2 = ptr4;
    for (int i = 4; i < 8; i++) {
        *(ptr4 + i) = i * 3;
    }
    for (int i = 0; i < 8; i++) {
        printf("%d ", *(ptr4 + i));
    }
    printf("\n");
    
    free(ptr);
    free(ptr3);
    free(ptr4);
}