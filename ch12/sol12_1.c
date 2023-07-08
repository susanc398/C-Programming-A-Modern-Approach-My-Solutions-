/* Reverses a message */

#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int ch, wordArray[MAX_SIZE], i = 0, *p;

    printf("Enter a message: ");

    while ((ch = getchar()) != '\n' && i < MAX_SIZE) {
        wordArray[i++] = ch;
    }

    for (p = wordArray + i - 1; p >= wordArray; p--)
        putchar(*p);
    printf("\n");
    
    return 0;
}