#include <stdio.h>
#include <stdlib.h>

#define PQ_SIZE 6

typedef int item_type;
typedef struct {
    item_type q[PQ_SIZE+1]; // here need to plus one because it starts from index 1
    int n;                  // count of the elements in the heap
} priority_queue;

int pq_parent(int);
int pq_young_child(int);
void bubble_up(priority_queue *, int);
void pq_insert(priority_queue *, item_type);
void pq_init(priority_queue *);
void make_heap(priority_queue *, item_type *, int);
void bubble_down(priority_queue *, int);
item_type extract_min(priority_queue *);
void heapsort(item_type *, int);

/*
 * test
 */
int main(void)
{
    int a[] = {1, 9, 3, 7, 5, 6};
    heapsort(a, 6);

    return 0;
}

int pq_parent(int n)
{
    if (n == 1)
        return -1;
    return n / 2;
}

int pq_young_child(int n)
{
    return 2 * n;
}

/********************* insert *************************/

void bubble_up(priority_queue *q, int p)
{
    if (pq_parent(p) == -1)
        return;
    if (q->q[pq_parent(p)] > q->q[p]) {
        //pq_swap(q, p, pq_parent(p));
        item_type temp = q->q[p];
        q->q[p] = q->q[pq_parent(p)];
        q->q[pq_parent(p)] = temp;

        bubble_up(q, pq_parent(p));
    }
}

void pq_insert(priority_queue *q, item_type x)
{
    if (q->n >= PQ_SIZE)
        printf("Warning: priority queue overflow insert x=%d\n", x);
    else {
        q->n = (q->n) + 1;      // start from index 1
        q->q[q->n] = x;
        bubble_up(q, q->n);
    }
}

/********************* make heap *************************/

void pq_init(priority_queue *q)
{
    q->n = 0;
}

void make_heap(priority_queue *q, item_type s[], int n)
{
    int i;
    pq_init(q);
    for(i = 0; i < n; i++)
        pq_insert(q, s[i]);
}

/********************* extract minimum ************************/

void bubble_down(priority_queue *q, int p)
{
    int c;
    int i;
    int min_index;
    
    c = pq_young_child(p);
    min_index = p;

    for (i = 0; i <= 1; i++)
        if (c+i <= q->n)
            if (q->q[min_index] > q->q[c+i])
                min_index = c+i;
    if (min_index != p) {
        //pq_swap(q, p, min_index);
        item_type temp = q->q[p];
        q->q[p] = q->q[min_index];
        q->q[min_index] = temp;

        bubble_down(q, min_index);
    }
}

item_type extract_min(priority_queue *q)
{
    int min = -1;
    if (q->n <= 0)
        printf("Warning: empty priority queue.\n");
    else {
        min = q->q[1];
        q->q[1] = q->q[q->n];
        q->n = q->n -1;
        bubble_down(q, 1);
    }
    return min;
}

/********************* heap sort ************************/

void heapsort(item_type s[], int n)
{
    int i;
    priority_queue q = {.n = 0};
    make_heap(&q, s, n);

    for (i = 0; i < n; i++) {
        s[i] = extract_min(&q);
        printf("%d\n", s[i]);       // just for test
    }
}
