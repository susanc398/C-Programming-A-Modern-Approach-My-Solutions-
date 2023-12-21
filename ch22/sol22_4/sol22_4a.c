/* Counts the numbers of letters in a text file */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int count = 0;

    if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (getc(fp) != EOF)
        count++;

    printf("There are %d characters in the file %s\n", count, argv[1]);

    fclose(fp);
    return 0;
}