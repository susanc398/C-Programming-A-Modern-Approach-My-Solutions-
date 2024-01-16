/* Accepts a line of text, then prints out whether it is a palindrome or not */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

bool is_palindrome(const char *message);

int main(void)
{
    int i = 0;
    char ch;
    char *message = malloc(sizeof(char) * (MAX_SIZE + 1));
    if (message == NULL) {
        fprintf(stderr, "Could not allocate memory for message\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter a message: ");
    while(1) {
        scanf("%1c", &ch);
        if (ch == '\n') break;
        if (isalpha(ch)) 
            message[i++] = tolower(ch);
    }
    message[i] = '\0';

    if (is_palindrome(message))
        printf("Palindrome\n");
    else 
        printf("Not a palindrome\n");

    free(message);
    return 0;
}

bool is_palindrome(const char *message)
{
    const char *p;
    char *q;
    char reverse[MAX_SIZE];

    q = reverse;

    for (p = message; *p != '\0'; p++)
        ;

    p--;
    while (*p) {
        *q++ = *p--;
    }
    *q = '\0';

    if (strcmp(reverse, message))
        return false;

    return true;
}