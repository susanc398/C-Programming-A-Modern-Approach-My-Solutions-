/* Prints a one-month calender */

#include <stdio.h>

int main(void)
{
    int days, start_day, i = 1;

    printf("Enter number of days in month: ");
    scanf("%d", &days);
    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start_day);

    while (i < start_day) {
        printf("   ");
        i++;
    }

    for (start_day = 1; start_day <= days; start_day++) {
        printf("%3d", start_day);
        if (i++ % 7 == 0)
            printf("\n");
    }
    printf("\n");

    return 0;
}