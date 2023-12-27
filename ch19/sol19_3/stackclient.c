#include <stdio.h>
#include "stackADT.h"

int main(void)
{
    Stack s1, s2;
    int n, len;

    s1 = create();
    s2 = create();

    push(s1, 1);
    len = length(s1);
    printf("Pushed 1 onto s1. The current length of s1 is %d\n", len);
    push(s1, 2);
    len = length(s1);
    printf("Pushed 2 onto s1. The current length of s1 is %d\n", len);

    n = pop(s1);
    len = length(s1);
    printf("Popped %d from s1. The current length of s1 is %d\n", n, len);
    push(s2, n);
    len = length(s2);
    printf("Pushed %d onto s2. The current length of s2 is %d\n", n, len);
    n = pop(s1);
    len = length(s1);
    printf("Popped %d from s1. The current length of s1 is %d\n", n, len);
    push(s2, n);
    len = length(s2);
    printf("Pushed %d onto s2. The current length of s2 is %d\n", n, len);

    destroy(s1);

    while(!is_empty(s2))
        printf("Popped %d from s2. The current length of s2 is %d\n", pop(s2), length(s2));

    push(s2, 3);
    len = length(s2);
    printf("Pushed 3 onto s2. The current length of s2 is %d\n", len);
    make_empty(s2);
    if (is_empty(s2))
        printf("s2 is empty\n");
    else 
        printf("s2 is not empty\n");

    destroy(s2);

    return 0;
}