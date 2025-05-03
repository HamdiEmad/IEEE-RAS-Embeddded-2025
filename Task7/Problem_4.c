#include <stdio.h>

typedef enum weekDay {
    Saturday,
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday
} day;

void check_day(day day) {
    if (day == Saturday || day == Sunday) {
        printf("It's a weekend!\n");
    } else {
        printf("It's a weekday.\n");
    }
}

int main() {
    day day1 = Wednesday;
    check_day(day1);
    day day2 = Saturday;
    check_day(day2);
    day day3 = Friday;
    check_day(day3);
}