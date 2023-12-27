/* Checks if a series of parentheses/brackets are nested properly */

#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
    Stack s = create();
    int ch;
    Item data;

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n') {
        if (ch == '(')
            push(s, (Item)ch);
        else if (ch == '{')
            push(s, (Item)ch);
        else if (ch == ')') {
            data = pop(s);
            if (data.op != '(') {
                printf("Parentheses/braces are not nested properly\n");
                exit(1);
            }
        } else if (ch == '}') {
            data = pop(s);
            if (data.op != '{') {
                printf("Parentheses/braces are not nested properly\n");
                exit(1);
            }
        }
    }

    printf("Parentheses/braces are nested properly\n");

    return 0;
}

