#ifndef QUEUEADT_H
#define QUEUEADT_H

#include <stdbool.h>

typedef struct queue_type *Queue;

static void terminate(const char *message);
Queue create(void);
void destroy(Queue q);
void enqueue(Queue q, int i);
void dequeue(Queue q);
int peek_first(Queue q);
int peek_last(Queue q);
bool is_empty(Queue q);
void make_empty(Queue q);
int length(Queue q);

#endif