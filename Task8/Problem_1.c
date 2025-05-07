#include <stdio.h>
#include <stdlib.h>

int size = 0;

// Comment and uncomment for choosing the sorting order
//#define ASCENDING
#define DESCENDING

int *getInput() {;
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        scanf("%d", arr + i);
    }
    return arr;
}

#ifdef DESCENDING
void *descending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
#endif

#ifdef ASCENDING
void *ascending(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
#endif

int main() {
    int *arr = getInput();

    #ifdef DESCENDING
    descending(arr, size);
    #endif

    #ifdef ASCENDING
    ascending(arr, size);
    #endif

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}