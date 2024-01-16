/* Computes the scrabble value of a word (function version) */

#include <ctype.h>
#include <stdio.h>

#define WORD_LEN 25

int compute_scrabble_value(const char *word);

int main(void)
{
    char scrabbleWord[WORD_LEN+1];
    int scrabbleValue;

    printf("Enter a word: ");
    scanf("%s", scrabbleWord);
    
    scrabbleValue = compute_scrabble_value(scrabbleWord);
    
    printf("Scrabble value: %d\n", scrabbleValue);

    return 0;
}

int compute_scrabble_value(const char *word)
{
    int value = 0, ch;
    const char *p = word;

    while (*p != '\0') {
        ch = toupper(*p);
        switch (ch) {
            case 65: case 69: case 73: case 76: case 78: case 79: case 82: case 83: case 84: case 85:
                value += 1;
                break;
            case 68: case 71:
                value += 2;
                break;
            case 66: case 67: case 77: case 80:
                value += 3;
                break;
            case 70: case 72: case 86: case 87: case 89:
                value += 4;
                break;
            case 75:
                value += 5;
                break;
            case 74: case 88:
                value += 8;
                break;
            case 81: case 90:
                value += 10;
                break;
        }
        p++;
    }

    return value;
}