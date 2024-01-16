/* Counts the number of vowels in a sentence */

#include <stdio.h>
#include <ctype.h>

#define MAX_SIZE 100

int compute_vowel_count(const char *sentence);

int main(void)
{
    char sentence[MAX_SIZE];
    int vowel_count; 

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SIZE, stdin);
    vowel_count = compute_vowel_count(sentence);

    printf("Your sentence contains %d vowels.\n", vowel_count);

    return 0;
}

int compute_vowel_count(const char *sentence)
{
    int num_vowels = 0;

    for (; *sentence != '\0'; sentence++) {
        if (*sentence == 65 || *sentence == 69 || *sentence == 73 || *sentence== 79 || *sentence == 85)
            num_vowels++;
        if (*sentence == 97 || *sentence == 101 || *sentence == 105 || *sentence== 111 || *sentence == 117)
            num_vowels++;
    }

    return num_vowels;
}