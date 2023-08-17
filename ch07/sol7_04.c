/* Translates an alphabetic phone number into numeric form */

#include <stdio.h>

int main(void)
{
    int ch;

    printf("Enter a phone number: ");
    while((ch = getchar()) != '\n') {
        if (ch >= 65 && ch <= 67)
            printf("2");
        else if (ch >= 68 && ch <= 70)
            printf("3");
        else if (ch >= 71 && ch <= 73)
            printf("4");
        else if (ch >= 74 && ch <= 76)
            printf("5");
        else if (ch >= 77 && ch <= 79)
            printf("6");
        else if (ch >= 80 && ch <= 83)
            printf("7");
        else if (ch >= 84 && ch <= 86)
            printf("8");
        else if (ch >= 87 && ch <= 90)
            printf("9");
        else
            putchar(ch);
    }
    printf("\n");

    return 0;
}