/* Determines whether two words are anagrams or not using functions */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void read_word(int counts[26]);
bool equal_array(int counts1[26], int counts2[26]);

int main(void)
{
    int letter_count1[26] = { 0 }, letter_count2[26] = { 0 };
    bool all_zeros;

    printf("Enter first word: ");
    read_word(letter_count1);
    printf("Enter second word: ");
    read_word(letter_count2);

    all_zeros = equal_array(letter_count1, letter_count2);

    if (all_zeros)
        printf("The words are anagrams.\n");
    else
        printf("The words are not anagrams.\n");

    return 0;
}

void read_word(int counts[26])
{
    int ch;

    while ((ch = getchar()) != '\n') {
        if (isalpha(ch))
            ch = tolower(ch);
            counts[ch-'a']++;
    }
}

bool equal_array(int counts1[26], int counts2[26])
{
    int i;

    for (i = 0; i < 26; i++) {
        if (counts1[i] != counts2[i])
            return false;
    }

    return true;
}