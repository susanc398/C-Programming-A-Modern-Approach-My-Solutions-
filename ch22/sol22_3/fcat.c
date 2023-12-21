/* Concatenates any number of files, writes to stdout */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int i, ch;

    if (argc < 2) {
        printf("usage: filename1 filename2 ...\n");
        exit(EXIT_FAILURE);
    }

    for (i = 1; i < argc; i++) {
        fp = fopen(argv[i], "rb");
        if (fp == NULL) {
            fprintf(stderr, "%s cannot be opened\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        while ((ch = getc(fp)) != EOF) 
            putchar(ch);

        fclose(fp);
    }
    printf("\n");

    return 0;
}