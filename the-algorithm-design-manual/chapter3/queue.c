#include <stdio.h>
#include <stdlib.h>

typedef int item_type;
typedef struct queue {
    item_type item;
    struct queue *next;
} queue;

queue *last_queue(queue *);
queue *penultima_queue(queue *);
void enqueue(item_type, queue **);
void dequeue(queue **);

/*
 * test
 */
int main(void)
{
    queue * pt;
    enqueue(1, &pt);
    dequeue(&pt);
    dequeue(&pt);
    enqueue(2, &pt);
    enqueue(3, &pt);
    enqueue(4, &pt);
    enqueue(2, &pt);
    dequeue(&pt);
    dequeue(&pt);
    dequeue(&pt);
    dequeue(&pt);
    dequeue(&pt);
    dequeue(&pt);

    return 0;
}

queue *last_queue(queue *q)
{
    if (q == NULL)
        return NULL;
    if (q->next == NULL)
        return q;
    return last_queue(q->next);
}

queue *penultima_queue(queue *q)
{
    /* if only one item in list */
    if (q->next == NULL)
        return NULL;
    /* if more than one item in list */
    if (q->next->next == NULL)
        return q;
    return penultima_queue(q->next);
    
}

void enqueue(item_type x, queue **q)
{
    queue *pt = malloc(sizeof(queue));
    pt->item = x;
    pt->next = *q;
    *q = pt;
    printf("enqueue: %2d\n", x);    // just for test
}

void dequeue(queue **q)
{
    queue *lq = last_queue(*q);
    if (lq != NULL) {
        printf("dequeue: %2d\n", lq->item); // just for test
        queue *pq = penultima_queue(*q);
        if (pq != NULL)
            pq->next = NULL;
        else
            *q = NULL;
        free(lq);
    }
    else
        printf("queue is empty now!\n");    // just for test
}
