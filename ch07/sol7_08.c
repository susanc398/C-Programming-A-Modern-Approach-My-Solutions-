/* Revision of chapter 5, programming project 8 to accept 12-hour time instead of 24-hour time */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int hour, minute, total;
    char am_or_pm;
    int d1, d2, d3, d4, d5, d6, d7, d8;
    d1 = (1305 + 480 - 1440) / 2;
    d2 = (480 + 583) / 2;
    d3 = (583 + 679) / 2;
    d4 = (679 + 767) / 2;
    d5 = (767 + 840) / 2;
    d6 = (840 + 945) / 2;
    d7 = (945 + 1140) / 2;
    d8 = (1140 + 1305) / 2;

    printf("Enter a 12-hour time: ");
    scanf("%d:%2d %1c", &hour, &minute, &am_or_pm);

    total = hour * 60 + minute;
    if (hour < 12 && toupper(am_or_pm) == 'P')
        total += 720;

    if (total <= d1)
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");
    else if (total > d1 && total <= d2)
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    else if (total > d2 && total <= d3)
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    else if (total > d3 && total <= d4)
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    else if (total > d4 && total <= d5)
        printf("Closest departure time is 12:47 p.m., arriving at 3:00 p.m.\n");
    else if (total > d5 && total <= d6)
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    else if (total > d6 && total <= d7)
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    else if (total > d7 && total <= d8)
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("Closest departure time is 9:45 p.m., arriving at 11:58 p.m.\n");

    return 0;
}