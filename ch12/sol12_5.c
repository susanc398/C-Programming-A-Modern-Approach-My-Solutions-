/* Reverses the words in a sentence (pointer version) */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 250

int main(void)
{
    int len = 0;
    char sentence[MAX_SIZE], reverse[MAX_SIZE];
    char *p, *r, *startpoint;

    printf("Enter a sentence: ");
    do {
        scanf("%c", &sentence[++len]);
    } while(sentence[len] != '.' && sentence[len] != '?' && sentence[len] != '!');

    p = sentence + len - 1;
    startpoint = sentence;
    r = reverse;

    while (p > sentence) {
        while (*--p != ' ');
        startpoint = p;
        while (*++p != ' ' && p < sentence + len)
            *r++ = *p;
        *r++ = ' ';
        p = startpoint;
    }

    printf("Reversal of sentence: ");
    for (r = reverse; *r != '\0'; r++)
        printf("%c", *r);
    
    for (p = sentence; *p != ' '; p++)
        printf("%c", *p);
    p = sentence + len;
    printf("%c\n", *p);

    return 0;
}