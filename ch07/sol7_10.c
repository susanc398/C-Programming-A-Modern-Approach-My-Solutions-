/* Counts the number of vowels in a sentence */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int ch, num_vowels = 0; 

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);
        if (ch == 65 ||ch == 69 || ch == 73 || ch == 79 || ch == 85)
            num_vowels++;
    }

    printf("Your sentence contains %d vowels.\n", num_vowels);

    return 0;
}