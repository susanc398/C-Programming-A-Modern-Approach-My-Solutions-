/* Evaluates RPN (Reverse Polish Notation) expressions */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

int main(void)
{
    int ch, first_val, second_val;
    
    for (;;) {
        printf("Enter an RPN expression: ");
        ch = getchar();
        if (ch == 'q') break;
        push(ch - '0');

        while ((ch = getchar()) != '\n') {
            if (isdigit(ch))
                push(ch-'0');

            switch (ch) {
                case '+': 
                    push(pop() + pop());
                    break;
                case '-': 
                    second_val = pop();
                    first_val = pop();
                    push(first_val - second_val);
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    second_val = pop();
                    first_val = pop();
                    push(first_val / second_val);
                    break;
                case '=':
                    printf("Value of expression: %d\n", pop());
                    break;
            }
        }
    }

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