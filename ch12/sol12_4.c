#include <ctype.h>
#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int ch, message[MAX_SIZE], i = 0, *p;

    printf("Enter a message: ");
    while((ch = getchar()) != '\n' && i < MAX_SIZE) {
        ch = toupper(ch);
        if (ch >= 65 && ch <= 90)
            message[i++] = ch;
    }
    
    p = message + i - 1;
    while (p >= message && *p-- == message[--i]);

    if (p == message)
        printf("Palindrome");
    else 
        printf("Not a palindrome");
    printf("\n");

    return 0;
}