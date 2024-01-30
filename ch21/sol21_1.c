#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

struct s {
    char a;
    int b[12];
    float c;
} S;

int main(int argc, char *argv[])
{
    printf("The size of struct s is %lu\n", sizeof(struct s));
    printf("The size of a is %lu and the offset is %lu\n", sizeof(S.a), offsetof(struct s, a));
    printf("The size of b is %lu and the offset is %lu\n", sizeof(S.b), offsetof(struct s, b));
    printf("The size of c is %lu and the offset is %lu\n", sizeof(S.c), offsetof(struct s, c));
    return 0;
}