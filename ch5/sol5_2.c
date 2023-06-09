/* Converts 24-hour time into 12-hour time */

#include <stdio.h>

int main(void)
{
    int hour, minute;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    if (hour >= 1 && hour<=11)
        printf("Equivalent 12-hour time: %d:%.2d AM\n", hour, minute);
    else if (hour == 12)
        printf("Equivalent 12-hour time: 12:%.2d PM\n", minute);
    else if (hour >= 13 && hour<=23)
        printf("Equivalent 12-hour time: %d:%.2d PM\n", hour % 12, minute);
    else 
        printf("Equivalent 12-hour time: 12:%.2d AM\n", minute);
    return 0;
}