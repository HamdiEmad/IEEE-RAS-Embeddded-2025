#include <stdio.h>

struct Employee {
    char *name;
    short id;
    float salary;
    char *job_title;
};

struct Dog {
    short age;
    char *name;
    char *food;
    char *owner_name;
    char *kind;
};

void print_employee_info(struct Employee employee) {
    printf("Name: %s\n", employee.name);
    printf("ID: %d\n", employee.id);
    printf("Salary: %.3f\n", employee.salary);    
    printf("Job Title: %s\n", employee.job_title);
}

void print_dog_info(struct Dog data) {
    printf("Age: %d\n", data.age);
    printf("Name: %s\n", data.name);
    printf("Food: %s\n", data.food);
    printf("Owner Name: %s\n", data.owner_name);
    printf("Kind: %s\n", data.kind);
}



int main() {
    struct Employee employee = {"Mohamed", 12345, 50000, "Software Engineer"};
    struct Dog dog = {3, "Milo", "Meat", "Mohamed", "male"};
    print_employee_info(employee);
    print_dog_info(dog);
}