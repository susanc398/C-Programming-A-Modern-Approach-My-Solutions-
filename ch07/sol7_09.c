/* Converts 12-hour time to 24-hour time */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int hour, minutes;
    char am_or_pm;

    printf("Enter a 12-hour time: ");
    scanf("%d:%2d%c", &hour, &minutes, &am_or_pm);

    if (toupper(am_or_pm) == 'A') {
        if (hour == 12)
            hour = 00;
    } else if (toupper(am_or_pm) == 'P') {
        if (hour < 12)
            hour = hour % 12 + 12;
    }

    printf("Equivalent 24-hour time: ");
    printf("%d:%2d\n", hour, minutes);

    return 0;
}