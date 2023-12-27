/* Evaluates RPN (Reverse Polish Notation) expressions */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

int main(void)
{
    Stack s = create();
    int ch, res, first_val, second_val;
    
    for (;;) {
        printf("Enter an RPN expression: ");
        ch = getchar();
        if (ch == 'q') break;
        push(s, ch - '0');

        while ((ch = getchar()) != '\n') {
            if (isdigit(ch))
                push(s, ch-'0');

            switch (ch) {
                case '+': 
                    res = pop(s) + pop(s);
                    push(s, res);
                    break;
                case '-': 
                    second_val = pop(s);
                    first_val = pop(s);
                    res = first_val - second_val;
                    push(s, res);
                    break;
                case '*':
                    res = pop(s) * pop(s);
                    push(s, res);
                    break;
                case '/':
                    second_val = pop(s);
                    first_val = pop(s);
                    res = first_val / second_val;
                    push(s, res);
                    break;
                case '=':
                    printf("Value of expression: %d\n", pop(s));
                    break;
            }
        }
    }

    return 0;
}