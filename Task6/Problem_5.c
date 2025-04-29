#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

void are_equal(struct Date *date1, struct Date *date2) {
    if (date1->day == date2->day && date1->month == date2->month && date1->year == date2->year) {
        printf("Dates are equal\n");
    } else {
        printf("Dates are not equal\n");
    }
}

int main() {
    struct Date date1 = {1, 1, 2022};
    struct Date date2 = {1, 1, 2022};
    struct Date date3 = {1, 2, 2023};
    struct Date date4 = {3, 4, 2024};

    struct Date *date_1 = &date1;
    struct Date *date_2 = &date2;
    struct Date *date_3 = &date3;
    struct Date *date_4 = &date4;

    are_equal(date_1, date_2);
    are_equal(date_1, date_3);
}