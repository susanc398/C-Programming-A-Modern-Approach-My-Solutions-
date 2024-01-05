/* Checks if a series of parentheses/brackets are nested properly */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int top = 0;

/*prototypes */
void make_empty(void);
bool is_empty();
bool is_full();
void push(int i);
int pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void)
{
    int ch;

    printf("Enter parentheses and/or braces: ");
    while ((ch = getchar()) != '\n') {
        if (ch == '(')
            push(ch);
        else if (ch == '{')
            push(ch);
        else if (ch == ')') {
            if (pop() != '(') {
                printf("Parentheses/braces are not nested properly\n");
                exit(1);
            }
        } else if (ch == '}') {
            if (pop() != '{') {
                printf("Parentheses/braces are not nested properly\n");
                exit(1);
            }
        }
    }

    printf("Parentheses/braces are nested properly\n");

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
    else
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
    printf("Parentheses/braces are not nested properly\n");
    exit(1);
}

void stack_underflow(void)
{
    printf("Parentheses/braces are not nested properly\n");
    exit(1);
}