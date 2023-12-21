/* Checks whether files can be opened for reading */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("usage: fopen filename1 filename2 ...\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    int i;

    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("%s cannot be opened\n", argv[i]);
            exit(EXIT_FAILURE);
        }
        printf("%s can be opened\n", argv[i]);
        fclose(fp);
    }

    return 0;
}