/* Finds the smallest and largest words in a series of words entered by user */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 20   /* maximum number of words */
#define WORD_LEN 20    /* max number of letters in word */

int read_line(char str[], int n);

int main(void)
{
    char word_list[MAX_WORDS][WORD_LEN+1];
    char word[WORD_LEN+1], smallest_word[WORD_LEN+1], largest_word[WORD_LEN+1];
    int num_words = 0, i;
    _Bool flag = true;

    for (;;) {
        if (!flag || num_words == MAX_WORDS) break;

        printf("Enter word: ");
        if (read_line(word, WORD_LEN) == 4)
            flag = false;

        strcpy(word_list[num_words], word);

        if (num_words == 0)
            strcpy(smallest_word, word);
        else if (strcmp(word_list[num_words], smallest_word) <= 0)
            strcpy(smallest_word, word_list[num_words]);

        if (strcmp(word_list[num_words], largest_word) >= 0)
            strcpy(largest_word, word_list[num_words]);

        num_words++;
    }

    
    printf("List of words:\n");
    for (i = 0; i < num_words; i++)
        printf(" %s\n", word_list[i]);
    printf("Smallest word: %s", smallest_word);
    printf("\nLargest word: %s\n", largest_word);

    return 0;
}

int read_line(char str[], int n) 
{
    int ch, i = 0;

    while ((ch = getchar()) != '\n' && i < n) 
        str[i++] = ch;

    str[i] = '\0';
    return i;
}