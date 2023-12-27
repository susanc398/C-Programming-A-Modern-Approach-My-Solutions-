#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

struct queue_type {
    int *contents;
    int top;
    int len;
};

static void terminate(const char *message)
{
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Queue create(int len)
{
   Queue q = malloc(sizeof(struct queue_type));
    if (q == NULL) 
        terminate("Error in create(); failed to allocate memory");
    q->contents = malloc(len*sizeof(int));
    if (q->contents == NULL) {
        free(q);
        terminate("Error in create(); failed to allocate memory");
    }
    q->top = 0;
    q->len = len;
    return q;
}

void destroy(Queue q)
{
    free(q);
}

void enqueue(Queue q, int val)
{
    if ((q->top + 1) == q->len) {
        q->len = 2 * q->len;
        q->contents = realloc(q->contents, q->len * sizeof(int));
    }

    q->contents[q->top++] = val;
}

void dequeue(Queue q)
{
    if (is_empty(q))
        terminate("Error in dequeue: queue is empty.");

    int i;
    
    for (i = 0; i < q->top - 1; i++) 
        q->contents[i] = q->contents[i + 1];

    q->top--;
}

int peek_first(Queue q)
{
    return q->contents[0];
}

int peek_last(Queue q)
{
    if (is_empty(q))
        terminate("Error in peek_last: queue is empty.");
    return q->contents[q->top - 1];
}

bool is_empty(Queue q)
{
    return q->contents == NULL;
}

void make_empty(Queue q)
{
    q->top = 0;
    free(q->contents);
}

int length(Queue q)
{
    return q->len;
}