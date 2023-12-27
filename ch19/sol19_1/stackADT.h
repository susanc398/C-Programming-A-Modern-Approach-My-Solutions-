#ifndef STACKADT_H
#define STACKADT_H

#include <stdbool.h>

typedef union {
    int value;
    char op;
} Item;

typedef struct stack_type *Stack;

static void terminate(const char *message);
Stack create(void);
void destroy(Stack s);
void make_empty(Stack s);
bool is_empty(Stack s);
bool is_full(Stack s);
void push(Stack s, Item i);
Item pop(Stack s);

#endif