#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

int main(int argc, char *argv[])
{
    Queue q1, q2;
    int i, val;

    q1 = create(10);
    q2 = create(20);

    for (i = 0; i < 10; i++) {
        enqueue(q1, i);
        printf("Enqueued %d onto q1. Length is now %d\n", peek_last(q1), length(q1));
        enqueue(q2, i * 2);
        printf("Enqueued %d onto q2. Length is now %d\n", peek_last(q2), length(q2));
    }

    for (i = 0; i < 10; i++) {
        val = peek_first(q1);
        dequeue(q1);
        printf("Dequeued %d from q1\n", val);
    }

    printf("\n");
    if (is_empty(q1))
        printf("Q1 is empty\n");
    else 
        make_empty(q1);

    if (is_empty(q2))
        printf("Q2 is empty\n");
    else    
        make_empty(q2);

    destroy(q1);
    destroy(q2);

    return 0;
}