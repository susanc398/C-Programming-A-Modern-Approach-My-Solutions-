/* Evaluates RPN (Reverse Polish Notation) expressions */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

/* prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);
int evaluate_RPN_expression(const char *expression);

int main(void)
{
    int i = 0, len;
    char ch;
    char *expression = malloc(sizeof(char) * STACK_SIZE);
    
    while (1) {
        printf("Enter an RPN expression: ");
        scanf(" %c", &ch);
        if (ch == 'q') break;
        expression[i++] = ch;
        while (1) {
            scanf(" %c", &ch);
            expression[i++] = ch;
            if (ch == '=') break;
        }

        printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
    }

    free(expression);
    return 0;
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void push(int i)
{
    if (is_full())
        stack_overflow();

    contents[top++] = i;
}

int pop(void)
{
    if (is_empty())
        stack_underflow();

    return contents[--top];
}

void stack_overflow(void)
{
    printf("Stack out of room.\n");
    exit(1);
}

void stack_underflow(void)
{
    printf("Not enough operands in expression.\n");
    exit(1);
}

int evaluate_RPN_expression(const char *expression)
{
    int i, len, ch, val = 0, d1, d2;
    len = strlen(expression);
    for (i = 0; i < len; i++) {
        ch = expression[i];
        if (isdigit(ch)) {
            push(ch - '0');
        } else {
            switch (ch) {
            case '+':
                val = pop() + pop();
                push(val);
                break;
            case '-':
                d2 = pop();
                d1 = pop();
                val = d1 - d2;
                push(val);
                break;
            case '*':
                val = pop() * pop();
                push(val);
                break;
            case '/':
                d2 = pop();
                d1 = pop();
                val = d1 / d2;
                push(val);
                break;
            case '=':
                val = pop();
                break;
            }
        }
    }
    return val;
}