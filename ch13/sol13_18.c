/* Accepts date in the form mm/dd/yyyy, then prints date in the form month dd, yyyy */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    char *months[] = {"January", "February", "March", "April", "May", "June", "July",
                     "August", "September", "October", "November", "December"};
    int month, day, year;

    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%4d", &month, &day, &year);

    printf("You entered the date %s %d, %4d\n", months[month - 1], day, year);

    return 0;
}