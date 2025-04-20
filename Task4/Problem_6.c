#include <stdio.h>

int main() {
    int a = 7;
    int *aptr = &a; // set aptr to the address of a

    /*
    Printing the address of a by usnig the reference operator(&)
    and by using the pointer variable aptr which points to the address in the memory.
    */
    printf("Address of a is %p\nValue of aPtr is %p\n", &a, aptr);

    /* 
    Printing the value of a by using data specifier(%d) for int 
    and by using the dereference operator(*) to get the value at the address in the memory.
    */
    printf("Value of a is %d\nValue of *aptr is %d\n", a, *aptr);

    /* 
    The dereference operator(*) can be used to get the value at the address in the memory.
    The reference operator(&) can be used to get the address of the variable.
    */
    printf("Showing that * and & are complement of each other\n");

    /*
    Printing the address of a by using the reference operator(&) of the dereferenced
    pointer variable aptr which gives the address of the dereferenced pointer.
    and by using the dereference operator(*) of the pointer variable aptr to get the 
    value at the address in the memory which is the address of a.
    */
    printf("&*aptr = %p\n*&aptr = %p\n", &*aptr, *&aptr);
}