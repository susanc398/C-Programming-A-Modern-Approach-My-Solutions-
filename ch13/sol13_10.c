/* Prints name in the format: last name, first initial. */

#include <ctype.h>
#include <stdio.h>

#define MAX_SIZE 50

void reverse_name(char *name);

int main(void)
{
    char name[MAX_SIZE];
    int ch, i = 0;

    printf("Enter a first and last name: ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch))
            name[i++] = ch;
    }
    name[i] = '\0';

    reverse_name(name);

    return 0;
}

void reverse_name(char *name)
{
    char *p;
    p = name;
    while (!isupper(*++p))
      ;

    while (*p)
        printf("%c", *p++);
    printf(", ");

    printf("%c.\n", name[0]);
}