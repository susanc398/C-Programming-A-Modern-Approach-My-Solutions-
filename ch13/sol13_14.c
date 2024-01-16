/* Modifies programming project 16 from chapter 8 to include functions */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 50 /* maximum length of word */

bool are_anagrams(const char *word1, const char *word2);

int main(void)
{
    char str1[MAX_SIZE], str2[MAX_SIZE];
    int ch, i = 0;

    printf("Enter first word: ");
    i = 0;
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch) && i < MAX_SIZE) 
            str1[i++] = tolower(ch);
    }
    str1[i] = '\0';

    printf("Enter second word: ");
    i = 0;
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch) && i < MAX_SIZE)
            str2[i++] = tolower(ch);
    }
    str2[i] = '\0';


    if (are_anagrams(str1, str2))
        printf("The words are anagrams.\n");
    else    
        printf("The words are not anagrams.\n");

    return 0;
}

bool are_anagrams(const char *word1, const char *word2)
{
    int letter_count[26] = { 0 };
    int ch, i;

    while (*word1) {
        ch = *word1++;
        letter_count[ch - 'a']++;
    }

    while (*word2) {
        ch = *word2++;
        letter_count[ch - 'a']--;
    }

    for (i = 0; i < 26; i++) {
        if (letter_count[i] != 0)
            return false;
    }

    return true;
}