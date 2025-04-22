#include <stdio.h>

void sort(int arr[], int n) {
    for (short i = 0; i < n; i++) {
        int *min = &arr[i];
        for (short j = i + 1; j < n; j++) {
            if (*min > arr[j]) {
                min = &arr[j];
            }
        }
        if (min != &arr[i]) {
            int temp = arr[i];
            arr[i] = *min;
            *min = temp;
        }
    }
    printf("Array in ascending order: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nArray in descending order: ");
    for (int i = n - 1; i > -1; i--)
        printf("%d ", arr[i]);
}

int main() {
    short num;
    scanf("%hd", &num);
    int arr[num];
    for (int i = 0; i < num; i++) 
        scanf("%d", &arr[i]);
    sort(arr, num);
}