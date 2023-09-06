/* Translates message to BIFF-speak */

#include <stdio.h>

#define SIZE 100

int main (void)
{
    int ch, len = 0, a[SIZE], i;

    printf("Enter message: ");
    while ((ch = getchar()) != '\n') {
        if (ch >= 97 && ch <= 122)
            ch -= 32; /* convert lower case to upper case by ASCII value */
        switch(ch) {
            case 65: ch = 52; break;
            case 66: ch = 56; break;
            case 69: ch = 51; break;
            case 73: ch = 49; break;
            case 79: ch = 48; break;
            case 83: ch = 53; break;
        }
        a[len++] = ch;
    }

    for (i = len; i < len + 10; i++)
        a[i] = '!';
    a[len+10] = '\n';

    printf("In BIFF-speak: ");
    for (i = 0; i < len + 11; i++)
        putchar(a[i]);

    return 0;
}