#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int ch, wordValue = 0;

    printf("Enter a word: ");
    while((ch = getchar()) != '\n') {
        ch = toupper(ch);

        switch (ch) {
            case 65: case 69: case 73: case 76: case 78: case 79: case 82: case 83: case 84: case 85:
                wordValue += 1;
                break;
            case 68: case 71:
                wordValue  += 2;
                break;
            case 66: case 67: case 77: case 80:
                wordValue += 3;
                break;
            case 70: case 72: case 86: case 87: case 89:
                wordValue += 4;
                break;
            case 75:
                wordValue += 5;
                break;
            case 74: case 88:
                wordValue += 8;
                break;
            case 81: case 90:
                wordValue += 10;
                break;
        }
    }

    printf("Scrabble value: %d\n", wordValue);

    return 0;
}
