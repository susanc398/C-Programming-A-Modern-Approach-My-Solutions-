/* Counts the number of lines in a text file */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int num_lines = 0, ch;
    bool line = false;

    if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        if (ch == '\n') {
            num_lines++;
            line = false;
        }
        line = true;
    }
    if (line)
        num_lines++;

    printf("There are %d lines in the file %s\n", num_lines, argv[1]);

    fclose(fp);
    return 0;
}