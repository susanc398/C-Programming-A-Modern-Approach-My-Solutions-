/* Calculates average length of words in a sentence */

#include <ctype.h>
#include <stdio.h>

int main(void)
{
    int ch, word_len = 0, num_words = 1;
    double average_len;

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n') {
        if (isspace(ch)) {
            num_words++;
        } else
            word_len++;
    }

    average_len = (double) word_len / num_words;

    printf("Average word length: %.1lf\n", average_len);

    return 0;
}