/* Tests whether two words are anagrams */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) 
{
    bool all_zeros = true;
    int ch, i, letter_count[26] = { 0 };

    printf("Enter first word: ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch))
            ch = tolower(ch);
            letter_count[ch-'a']++;
    }

    printf("Enter second word: ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch))
            ch = tolower(ch);
            letter_count[ch-'a']--;
    }

    for (i = 0; i < 26; i++) {
        if (letter_count[i] != 0)
            all_zeros = false;
    }

    if (all_zeros)
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}