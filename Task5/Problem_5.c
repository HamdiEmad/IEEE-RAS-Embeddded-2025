#include <stdio.h>

void returnOdd(int arr[], int n) {
    int *odd = arr;
    short oddCount = 0;
    printf("Odd numbers are: ");
    while (n--) {
        if (*odd % 2 == 1) {
            oddCount++;
            printf("%d ", *odd);
        }
        odd++;
    }
    printf("\nTotal odd numbers: %hd\n", oddCount);
}

int main() {
    short num;
    scanf("%hd", &num);
    int arr[num];
    for (int i = 0; i < num; i++) 
        scanf("%d", &arr[i]);
    returnOdd(arr, num);
}