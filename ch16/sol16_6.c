/* Prompts user to enter two dates, returns statement on which one is earlier */

#include <stdio.h>
#include <stdlib.h>

struct date {
    int month;
    int day;
    int year;
} d1, d2;

int day_of_year(struct date d);
int compare_dates(struct date d1, struct date d2);

int main(int argc, char* argv[])
{
    int res;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d1.month, &d1.day, &d1.year);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &d2.month, &d2.day, &d2.year);

    res = compare_dates(d1, d2);
    if (res == -1)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", d1.month, d1.day, d1.year, d2.month, d2.day, d2.year);
    if (res == 1)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", d2.month, d2.day, d2.year, d1.month, d1.day, d1.year);

    return 0;
}

int day_of_year(struct date d)
{
    int days = 0;

    switch (d.month) {
        case 12:
            days += 31;
        case 11:
            days += 30;
        case 10:
            days += 31;
        case 9:
            days += 30;
        case 8: case 7:
            days += 31;
        case 6: 
            days += 30;
        case 5: 
            days += 31;
        case 4: 
            days += 30;
        case 3: 
            days += 31;
        case 2:
            if (d.year % 4 == 0)
                days += 29;
            else
                days += 28;
        case 1:
            days += 31;
        default: break;
    }

    days += d.day;

    return days;
}

int compare_dates(struct date d1, struct date d2)
{
    int d1_days, d2_days;

    d1_days = day_of_year(d1);
    d2_days = day_of_year(d2);

    if (d1.year < d2.year)
        return -1;
    else if (d2.year < d1.year)
        return 1;

    if (d1_days < d2_days)
        return -1;
    return 1;
}