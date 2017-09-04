#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"

bool processed[MAXV+1];     // which vertices have been processed
bool discovered[MAXV+1];    // which vertices have been found
int parent[MAXV+1];         // discovery relation

void initialize_search(graph *g)
{
    int i;
    for (i = 1; i <= g->nvertices; i++) {
        processed[i] = discovered[i] = FALSE;
        parent[i] = -1;
    }
}

void process_vertex_late(int v)
{
}

void process_vertex_early(int v)
{
}

void process_edge(int x, int y)
{
    printf("processed edge (%d,%d)\n", x, y);
}

void bfs(graph *g, int start)
{
    int v;          // current vertex
    int y;          // successor vertex
    edgenode *p;    // temporary pointer

    /* initialize queue */
    /* or use: queue *q = NULL; */
    queue *q = malloc(sizeof(queue));
    q = NULL;

    printf("%p\n", q);
    enqueue(&q, start);
    discovered[start] = TRUE;

    while (empty_queue(&q) == FALSE) {
        v = dequeue(&q);
        // process_vertex_early(v);
        processed[v] = TRUE;
        p = g->edges[v];
        while (p != NULL) {
            y = p->y;
            if ((processed[y] == FALSE) || g->directed) {
                process_edge(v, y);
            }
            if (discovered[y] == FALSE) {
                enqueue(&q, y);
                discovered[y] = TRUE;
                parent[y] = v;
            }
            p = p->next;
        }
        // process_vertex_late(v);
    }
}
