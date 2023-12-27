#include <stdio.h>
#include <stdlib.h>
#include "stackADT.h"

struct node {
    void *data;
    struct node *next;
};

struct stack_type {
    int len;
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
        terminate("Error in create: stack could not be created.");
    s->len = 0;
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

void push(Stack s, void *p)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in push: stack is full.");
    
    new_node->data = p;
    new_node->next = s->top;
    s->top = new_node;
    s->len++;
}

void *pop(Stack s)
{
    struct node *old_top;
    void *p;

    if(is_empty(s))
        terminate("Error in pop: stack is empty.");

    old_top = s->top;
    p = old_top->data;
    s->top = old_top->next;
    free(old_top);
    s->len--;
    return p;
}

int length(Stack s)
{
    return s->len;
}