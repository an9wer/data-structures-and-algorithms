#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"

bool processed[MAXV+1];     // which vertices have been processed
bool discovered[MAXV+1];    // which vertices have been found
int parent[MAXV+1];         // discovery relation
int entry_time[MAXV+1];
int exit_time[MAXV+1];

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

void dfs(graph *g, int v)
{
    printf("start %d\n", v);    // just for test
    edgenode *p;
    int y;
    
    /*
    if (finished)
        return;
    */

    discovered[v] = TRUE;
    /*
    time = time + 1;
    entry_time[v] = time;
    */

    // process_vertex_early(v);

    p = g->edges[v];
    while (p != NULL) {
        y = p->y;
        if (discovered[y] == FALSE) {
            parent[y] = v;
            process_edge(v, y);
            dfs(g, y);
        }
        /*
        else if ((!processed[y]) || (g->directed))
            process_edge(v, y);
        */

        /*
        if (finished)
            return;
        */

        p = p->next;
    }

    // process_vertex_late(v);
    
    /*
    time = time + 1;
    exit_time[v] = time;
    */

    processed[v] = TRUE;
    printf("end %d\n", v);  // just for test
}
