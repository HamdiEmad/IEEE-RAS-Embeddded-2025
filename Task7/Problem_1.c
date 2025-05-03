#include <stdio.h>

struct student_info {
    unsigned Roll_number : 4;
    unsigned Age : 8;
    unsigned Marks : 3;
    unsigned : 0;
    char *Address;
    char *Name;
};

void print_student_info(struct student_info *s, int count) {
    for (int i = 0; i < count; i++) {
        printf("Roll number: %d\n", s[i].Roll_number);
        printf("Age: %d\n", s[i].Age);
        printf("Marks: %d\n", s[i].Marks);
        printf("Address: %s\n", s[i].Address);
        printf("Name: %s\n\n\n", s[i].Name);
    }
}

int main() {
    struct student_info s[5];
    s[0].Roll_number = 1;
    s[0].Age = 20;
    s[0].Marks = 3;
    s[0].Address = "123 Main Street";
    s[0].Name = "John Doe";

    s[1].Roll_number = 2;
    s[1].Age = 21;
    s[1].Marks = 4;
    s[1].Address = "456 Second Street";
    s[1].Name = "Jane Doe";

    s[2].Roll_number = 3;
    s[2].Age = 22;
    s[2].Marks = 5;
    s[2].Address = "789 Third Street";
    s[2].Name = "Bob Smith";

    s[3].Roll_number = 4;
    s[3].Age = 23;
    s[3].Marks = 6;
    s[3].Address = "1011 Fourth Street";
    s[3].Name = "Alice Johnson";

    s[4].Roll_number = 5;
    s[4].Age = 24;
    s[4].Marks = 7;
    s[4].Address = "1213 Fifth Street";
    s[4].Name = "Charlie Brown";

    print_student_info(s, 5);
    printf("Size of struct: %zu bytes\n", sizeof(struct student_info));
}

/*
    The cpu will handle the bit fields in the struct using the allignment rules of the cpu.
    roll_number, age and marks are bit fields in bits which access needs bitwise operations.
    address and name are strings wich are stored sequentially in memory and be accessed using pointers.
    
*/