#include <ctype.h>
#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int ch, message[MAX_SIZE], i = 0, *p, *q;

    printf("Enter a message: ");
    while((ch = getchar()) != '\n' && i < MAX_SIZE) {
        ch = toupper(ch);
        if (ch >= 65 && ch <= 90)
            message[i++] = ch;
    }

    p = &message[i - 1];
    q = &message[0];

    while (*p == *q && p > &message[0] && q < &message[i - 1]) {
        p--;
        q++;
    }

    if (p == &message[0])
        printf("Palindrome");
    else 
        printf("Not a palindrome");
    printf("\n");

    return 0;
}