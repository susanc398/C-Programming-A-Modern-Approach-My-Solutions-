/* Finds which date come earlier on the calender */

#include <stdio.h>

int main(void)
{
    int year, month, day;
    int earliest_year, earliest_month, earliest_day;

    for (;;) {
        printf("Enter a date (mm/dd/yy): ");
        scanf("%d/%d/%2d", &month, &day, &year);

        if (month == 0 && day == 0 && year == 0) break;

        if (year < earliest_year) {
            earliest_year = year;
            earliest_month = month;
            earliest_day = day;
        } else if (earliest_year < year) {
            continue;
        } else if (month < earliest_month) {
            earliest_year = year;
            earliest_month = month;
            earliest_day = day;
        } else if (earliest_month < month) {
            continue;
        } else if (day < earliest_day) {
            earliest_year = year;
            earliest_month = month;
            earliest_day = day;
        }
    }

    printf("%d/%d/%.2d is the earliest date\n", earliest_month, earliest_day, earliest_year);

    return 0;
}