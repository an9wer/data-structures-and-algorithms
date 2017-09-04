#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"

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

void enqueue(queue **q, item_type x)
{
    queue *pt = malloc(sizeof(queue));
    pt->item = x;
    pt->next = *q;
    *q = pt;
    printf("enqueue: %2d\n", x);    // just for test
}

item_type dequeue(queue **q)
{
    queue *lq = last_queue(*q);
    if (lq != NULL) {
        printf("dequeue: %2d\n", lq->item); // just for test
        item_type rv = lq->item;
        queue *pq = penultima_queue(*q);
        if (pq != NULL)
            pq->next = NULL;
        else
            *q = NULL;
        free(lq);
        return rv;
    }
    else
        printf("queue is empty now!\n");    // just for test
}

bool empty_queue(queue **q)
{
    if (*q == NULL)
        return TRUE;
    return FALSE;
}
