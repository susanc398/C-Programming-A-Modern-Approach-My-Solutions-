/* Implements the Caeser cipher */

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

void encrypt(char *message, int shift);

int main(void)
{
    char message[MAX_SIZE+1];
    int shift, i;

    printf("Enter message to be encrypted: ");
    fgets(message, MAX_SIZE+1, stdin);

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    encrypt(message, shift);

    printf("Encrypted message: ");
    for (i = 0; i < strlen(message); i++)
        printf("%c", message[i]);

    return 0;
}

void encrypt(char *message, int shift)
{
    int ch, len;
    char *p;

    len = strlen(message);

    for (p = message; p < message + len; p++) {
        ch = *p;
        if (isupper(ch))
            *p = ((ch - 'A') + shift) % 26 + 'A';
        else if (islower(ch))
            *p = ((ch - 'a') + shift) % 26 + 'a';
    }
}