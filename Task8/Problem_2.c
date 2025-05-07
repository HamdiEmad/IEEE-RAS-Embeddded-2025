#include <stdio.h>

#define ADD
//#define SUBTRACT

#define add(a, b) ((a) + (b))
#define subtract(a, b) ((a) - (b))


int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    #ifdef ADD
    printf("The sum is: %d", add(a, b));
    #endif

    #ifdef SUBTRACT
    printf("The difference is: %d", subtract(a, b));
    #endif  
}