/* Translates an alphabetic phone number into numeric form */

#include <stdio.h>

int main(void)
{
    int ch, i = 0, j;
    char number[15];

    printf("Enter a phone number: ");
    while ((ch = getchar()) != '\n' && i < 15) {
        if (ch >= 65 && ch <= 67)
            number[i] = '2';
        else if (ch >= 68 && ch <= 70)
            number[i] = '3';
        else if (ch >= 71 && ch <= 73)
            number[i] = '4';
        else if (ch >= 74 && ch <= 76)
            number[i] = '5';
        else if (ch >= 77 && ch <= 79)
            number[i] = '6';
        else if (ch >= 80 && ch <= 83)
            number[i] = '7';
        else if (ch >= 84 && ch <= 86)
            number[i] = '8';
        else if (ch >= 87 && ch <= 90)
            number[i] = '9';
        else
            number[i] = ch;
        i++;
    }

    for (j = 0; j < i; j++)
        printf("%c", number[j]);
    printf("\n");

    return 0;
}