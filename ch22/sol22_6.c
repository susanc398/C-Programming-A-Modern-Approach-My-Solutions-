/* Displays the contents of a file as bytes and characters */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 500

typedef unsigned char BYTE;

int main(int argc, char *argv[])
{
    FILE *fp;
    int i = 0, ch, offset = 0, spaces_left;
    BYTE buf[MAX_SIZE], *ptr, *endAddr;

    if (argc != 2) {
        printf("usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    fp = fopen(argv[1], "rb+");
    if (fp == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fp) {
        if (fread(&buf[i++], sizeof(BYTE), 1, fp) != 1)
            break;
    }

    printf("Offset              Bytes              Characters\n");
    printf("------  -----------------------------  ----------\n");

    endAddr = buf + i;
    for (ptr = buf; ptr < endAddr; ptr += 10) {
        printf("%-6d  ", offset);
        for (i = 0; i < 10 && ptr + i < endAddr; i++) 
            printf("%.2X ", *(ptr + i));
        spaces_left = 29 - ((i * 3) - 1);
        for (i = 0; i < spaces_left; i++)
            printf(" ");
        printf("  ");
        for (i = 0; i < 10 && ptr + i < endAddr; i++) {
            BYTE ch = *(ptr + i);
            if (!isprint(ch))
                ch = '.';
            printf("%c", ch);
        }
        printf("\n");
        offset += 10;
    }

    fclose(fp);
    return 0;
}