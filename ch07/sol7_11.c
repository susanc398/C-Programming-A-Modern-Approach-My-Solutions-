/* Prints name in the format: last name, first initial. */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int ch, first_initial, last_initial;

    printf("Enter a first and last name: ");

    while (isspace(first_initial = getchar()));

    while (!isspace(getchar()));

    while(isspace(last_initial = getchar()));

    putchar(last_initial);
    while (!isspace(ch = getchar()))
        putchar(ch);

    printf(", %c.\n", first_initial);

    return 0;
}