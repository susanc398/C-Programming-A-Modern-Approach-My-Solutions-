/* Implements the Caeser cipher */

#include <ctype.h>
#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int ch, i = 0, shift, len = 0, shift_ch;
    char message[MAX_SIZE];

    printf("Enter message to be encrypted: ");
    while ((ch = getchar()) != '\n') {
        message[i++] = ch;
        len++;
    }
    
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    for (i = 0; i < len; i++) {
        ch = message[i];
        if (isupper(ch))
            message[i] = ((ch - 'A') + shift) % 26 + 'A';
        else if (islower(ch)) 
            message[i] = ((ch - 'a') + shift) % 26 + 'a';
    }

    printf("Encrypted message: ");
    for (i = 0; i < len; i++)
        printf("%c", message[i]);
    printf("\n");

    return 0;
}