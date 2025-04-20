#include <stdio.h>

int main() {
    int num = 21;
    int *ptrINT = &num; // Pointer to num
    printf("%d\n", *ptrINT); // Dereference ptr to get the value of num
    printf("%p\n", ptrINT); // Print the address of num using ptr
    
    char character = 'a';
    char *ptrCHAR = &character; // Pointer to a
    printf("%c\n", *ptrCHAR); // Dereference ptr to get the value of a
    printf("%p\n", ptrCHAR); // Print the address of a using ptr
    
    float floatingNum = 3.14;
    float *ptrFLOAT = &floatingNum; // Pointer to floatingNum
    printf("%f\n", *ptrFLOAT); // Dereference ptr to get the value of floatingNum
    printf("%p\n", ptrFLOAT); // Print the address of floatingNum using ptr
    
    double doubleNum = 3.14159265358979323846;
    double *ptrDOUBLE = &doubleNum; // Pointer to doubleNum
    printf("%lf\n", *ptrDOUBLE); // Dereference ptr to get the value of doubleNum
    printf("%p\n", ptrDOUBLE); // Print the address of doubleNum using ptr
}