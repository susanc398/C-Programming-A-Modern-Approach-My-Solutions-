/* Reverses a message */

#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int ch, message[MAX_SIZE], len = 0, *p;

    printf("Enter a message: ");
    while((ch = getchar()) != '\n') {
        message[len++] = ch;
    }

    for (p = &message[len - 1]; p >= &message[0]; p--)
        printf("%c", *p);
    printf("\n");

    return 0;
}