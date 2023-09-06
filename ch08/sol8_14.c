/* reverses the words in a sentence */

#include <stdio.h>

#define MAX_SIZE 250

int main(void)
{
    int len = -1, i, j = 0, endWord, startWord;
    char sentence[MAX_SIZE], reverse[MAX_SIZE];

    printf("Enter a sentence: ");
    do {
        scanf("%c", &sentence[++len]);
    } while(sentence[len] != '.' && sentence[len] != '?' && sentence[len] != '!');
    
    endWord = len - 1;
    startWord = len - 1;

    while (startWord > 0) {
        if (sentence[startWord--] == ' ') {
            i = startWord + 1;
            while (i < endWord) 
                reverse[j++] = sentence[++i];
            reverse[j++] = ' ';
            endWord = startWord;
        }
    }
    for(i = 0; i <= endWord; i++)
        reverse[j++] = sentence[i];
    reverse[j] = sentence[len];

    printf("Reversal of sentence: ");
    for(i = 0; i <= len; i++)
        printf("%c", reverse[i]);
    printf("\n");

    return 0;
}