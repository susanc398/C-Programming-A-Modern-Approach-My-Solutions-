/* Modifies programming project 5 from chapter 7 so that SCRABBLE values of letters are stored in array */

#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int letter_values[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int i, letter, points = 0;

    printf("Enter a word: ");
    while((letter = getchar()) != '\n') {
        letter = toupper(letter);
        points += letter_values[letter - 'A'];
    }

    printf("Scrabble value: %d\n", points);

    return 0;
}