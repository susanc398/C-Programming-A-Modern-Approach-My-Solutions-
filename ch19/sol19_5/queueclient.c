#include <stdio.h>
#include <stdlib.h>
#include "queueADT.h"

int main(void)
{
    Queue q1, q2, q3, q4;
    int i, val;

    q1 = create();
    q2 = create();

    for (i = 1; i < 10; i++) {
        enqueue(q1, i);
        printf("Enqueued %d onto q1. Length is now %d\n", peek_last(q1), length(q1));
        enqueue(q2, i * 10);
        printf("Enqueued %d onto q2. Length is now %d\n", peek_last(q2), length(q2));
    }
    printf("\n");
    printf("The first value in q1 is %d\n", peek_first(q1));
    printf("The first value in q2 is %d\n", peek_first(q2));
    printf("\n");
    for (i = 9; i > 0; i--) {
        val = peek_last(q1);
        dequeue(q1);
        printf("Dequeued %d from q1. Length is now %d\n", val, length(q1));
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