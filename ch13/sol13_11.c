/* Calculates average length of words in a sentence */

#include <ctype.h>
#include <stdio.h>

#define MAX_SIZE 500

double compute_average_word_length(const char *sentence);

int main(void)
{
    double average_len;
    char sentence[MAX_SIZE];

    printf("Enter a sentence: ");
    fgets(sentence, MAX_SIZE, stdin);
    average_len = compute_average_word_length(sentence);

    printf("Average word length: %.1lf\n", average_len);

    return 0;
}

double compute_average_word_length(const char *sentence)
{
    int num_words = 1, word_len = 0;

    for (; *sentence != '\0'; sentence++) {
        if (isspace(*sentence))
            num_words++;
        else
            word_len++;
    }

    return (double) word_len / num_words;
}

