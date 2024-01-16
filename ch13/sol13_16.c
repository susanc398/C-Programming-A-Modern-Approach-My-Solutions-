/* Reverses a message */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void reverse(char *message);

int main(void)
{
    int ch, len = 0, *p;
    char *message = malloc(sizeof(char *) * (MAX_SIZE + 1));
    if (message == NULL) {
        fprintf(stderr, "Cannot allocate memory for message\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter a message: ");
    while((ch = getchar()) != '\n') {
        message[len++] = ch;
    }

    reverse(message);

    free(message);
    return 0;
}

void reverse(char *message)
{
    char *p;
    
    for (p = message; *p != '\0'; p++) 
        ;

    while (p-- != message) {
        printf("%c", *p);
    }
    printf("\n");
}