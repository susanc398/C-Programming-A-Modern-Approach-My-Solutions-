#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct node {
    int value;
    struct node *next;
};

struct queue_type {
    int len;
    struct node *top;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(void)
{
    Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL)
        terminate("Error in create: failed to create queue.");
    
    q->top = NULL;
    q->len = 0;
    return q;
}

void destroy(Queue q)
{
    if (q != NULL)
        make_empty(q);
    free(q);
}

void enqueue(Queue q, int i)
{
    struct node *new_node = malloc(sizeof(struct node));
    if (new_node == NULL)
        terminate("Error in enqueue: queue is full.");
    
    new_node->value = i;
    new_node->next = q->top;
    q->top = new_node;
    q->len++;
}

void dequeue(Queue q)
{
    if (is_empty(q))
        terminate("Error in queue: queue is empty.");

    int i;
    struct node *temp = q->top;

    i = temp->value;
    q->top = temp->next;
    q->len--;
    free(temp);
}

int peek_first(Queue q)
{
    struct node *p;

    if (q == NULL)
        terminate("Error in peek_first: queue is empty.");

    for (p = q->top; p->next != NULL; p = p->next)
        ;
    
    return p->value;
}

int peek_last(Queue q)
{
    struct node *last = q->top;
    return last->value;
}

bool is_empty(Queue q)
{
    return q->top == NULL;
}

void make_empty(Queue q)
{
    while (!is_empty(q))
        dequeue(q);
}

int length(Queue q)
{
    return q->len;
}