/* Converts all letters in a file to upper case, outputs to stdout */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ch;

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) 
        putchar(toupper(ch));
    printf("\n");

    fclose(fp);
    return 0;
}