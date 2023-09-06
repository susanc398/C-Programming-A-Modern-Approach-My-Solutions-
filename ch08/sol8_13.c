/* Modifies chapter 7 programming project 11 to use array to store last name */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int ch, first_initial, last_name[20], i, len = 0;
    printf("Enter a first and last name: ");

    while (isspace(first_initial = getchar()));

    while (!isspace(getchar()));

    while (isspace(ch = getchar()));

    last_name[len++] = ch;
    while (!isspace(ch = getchar())) {
        last_name[len++] = ch;
    }

    for (i = 0; i < len; i++)
        printf("%c", last_name[i]);
    printf(", %c.\n", first_initial);

    return 0;
}