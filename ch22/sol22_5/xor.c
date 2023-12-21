/* Performs XOR encryption */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY '&'
#define MAX_SIZE 1000

int main(int argc, char *argv[])
{
    FILE *source_file, *dest_file;
    int orig_char, new_char, i = 0, buf_len;
    unsigned char buf[MAX_SIZE];
    
    if (argc != 3) {
        printf("usage: xor sourcefile destfile");
        exit(EXIT_FAILURE);
    }

    source_file = fopen(argv[1], "rb");
    if (source_file == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    dest_file = fopen(argv[2], "wb");
    if (dest_file == NULL) {
        fprintf(stderr, "%s cannot be opened\n", argv[2]);
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    if (source_file) {
        while (fread(&buf[i], sizeof(buf[0]), 1, source_file) == 1)
            i++;
    }
    buf_len = i;

    for (i = 0; i < buf_len; i++) {
        if (isalpha(buf[i])) {
            orig_char = buf[i];
            new_char = orig_char ^ KEY;
            buf[i] = new_char;
        }
    }

    for (i = 0; i < buf_len; i++) 
        fwrite(&buf[i], sizeof(buf[0]), 1, dest_file);

    fclose(source_file);
    fclose(dest_file);
    return 0;
}