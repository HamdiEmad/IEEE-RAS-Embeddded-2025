#include <stdio.h>
#include <stdlib.h>

struct Employee {
    char *name;
    short id;
};

void free_employee(struct Employee *employee) {
    if (employee == NULL) {
        return;
    }
    free(employee->name);
    free(employee);
}

int main() {
    struct Employee *employee = malloc(sizeof(struct Employee));
    employee->name = malloc(30 * sizeof(char));
    snprintf(employee->name, 30, "Abo Al-Qassem");
    printf("Name: %s\n", employee->name);
    employee->id = 12345;
    free_employee(employee);
}