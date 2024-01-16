#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 30

int main(int argc, char *argv[])
{
    char words[MAX_WORDS][MAX_WORD_LEN+1];
    char word_str[MAX_WORD_LEN+1];
    char last_ch;
    char *p, *q;
    int num_words = 0, i = 0, j = 0, ch;

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n') {

        if (isalpha(ch)) 
            word_str[j++] = ch;

        if (ch == ' ' || ch == '.' || ch == '?' || ch == '!') {
            word_str[j] = '\0';
            strcpy(words[i++], word_str);
            memset(word_str, 0, sizeof(word_str));
            j = 0;

            num_words++;
            if (ch == '.' || ch == '?' || ch == '!')
                last_ch = ch;
        }
    };

    for (i = num_words - 1; i > 0; i--) {
        printf("%s ", words[i]);
    }
    printf("%s%c\n", words[0], last_ch);

    return 0;
}
