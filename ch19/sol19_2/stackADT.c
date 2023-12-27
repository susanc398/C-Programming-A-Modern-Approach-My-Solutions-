#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
    int value;
    struct node *next;
};

struct stack_type 
{
    struct node *top;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(void)
{
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: failed to create stack\n");

    s->top = NULL;
    return s;
}

void destroy(Stack s)
{
    make_empty(s);
    free(s);
}

void make_empty(Stack s)
{
    while (!is_empty(s))
        pop(s);
}

bool is_empty(Stack s)
{
    return s->top == NULL;
}

bool is_full(Stack s)
{
    return false;
}

void push(Stack s, int i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full\n");

    new_node->value = i;
    new_node->next = s->top;
    s->top = new_node;
}

int pop(Stack s)
{
    if (is_empty(s))
        terminate("Error in pop: stack is empty\n");

    struct node *temp = s->top;
    int i;

    i = temp->value;
    s->top = temp->next;
    free(temp);

    return i;
}