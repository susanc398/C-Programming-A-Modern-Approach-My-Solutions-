#include <stdio.h>
#include "stackADT.h"

int main(void)
{
    Stack s1, s2;
    int len;
    char *str1 = "Hello", *str2 = "World", *str3 = "Hello world!", *str;

    s1 = create();
    s2 = create();

    push(s1, str1);
    len = length(s1);
    printf("Pushed \"%s\" onto s1. The current length of s1 is %d\n", (char*)str1, len);
    push(s1, str2);
    len = length(s1);
    printf("Pushed \"%s\" onto s1. The current length of s1 is %d\n", (char*)str2, len);

    str = pop(s1);
    len = length(s1);
    printf("Popped \"%s\" from s1. The current length of s1 is %d\n", (char*)str, len);
    push(s2, str);
    len = length(s2);
    printf("Pushed \"%s\" onto s2. The current length of s2 is %d\n", (char*)str, len);
    str = pop(s1);
    len = length(s1);
    printf("Popped \"%s\" from s1. The current length of s1 is %d\n", (char*)str, len);
    push(s2, str);
    len = length(s2);
    printf("Pushed \"%s\" onto s2. The current length of s2 is %d\n", (char*)str, len);

    destroy(s1);

    while(!is_empty(s2))
        printf("Popped \"%s\" from s2. The current length of s2 is %d\n", (char*)pop(s2), length(s2));

    push(s2, str3);
    len = length(s2);
    printf("Pushed \"%s\" onto s2. The current length of s2 is %d\n", (char*)str3, len);
    make_empty(s2);
    if (is_empty(s2))
        printf("s2 is empty\n");
    else 
        printf("s2 is not empty\n");

    destroy(s2);

    return 0;
}