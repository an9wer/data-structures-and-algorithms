#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"

void initialize_graph(graph *g, bool directed)
{
    int i;      // counter
    
    g -> nvertices = 0;
    g -> nedges = 0;
    g -> directed = directed;

    for (i = 1; i <= MAXV; i++)
        g -> degree[i] = 0;
    for (i = 1; i <= MAXV; i++)
        g -> edges[i] = NULL;
}

void read_graph(graph *g, bool directed)
{
    int i;      // counter
    int m;      // number of edges
    int x, y;   // vertices in edge (x, y)

    initialize_graph(g, directed);

    printf("enter nvertices and nedges: ");
    scanf("%d%d", &(g->nvertices), &m);
    
    for (i = 1; i <= m; i++) {
        printf("enter vertex x and y: ");
        scanf("%d%d", &x, &y);
        insert_edge(g, x, y, directed);
    }
}

/*
 * an edge (x, y), the vertices x and y are said to be 
 * incident to the edge and adjacent to each other.
 */
void insert_edge(graph *g, int x, int y, bool directed)
{
    /*
     * param x: the vertex x of edge(x, y)
     * param y: the vertex y of edge(x, y)
     */

    edgenode *p;    // temporary pointer
    
    p = malloc(sizeof(edgenode));

    p -> weight = NULL;
    p -> y = y;
    p -> next = g -> edges[x];

    g -> edges[x] = p;
    g -> degree[x] ++;

    if (directed == FALSE)
        insert_edge(g, y, x, TRUE);
    else
        g -> nedges ++;
}

void print_graph(graph *g)
{
    int i;          // counter
    edgenode *p;    // temporary pointer

    for (i = 1; i <= g->nvertices; i++) {
        printf("%d: ", i);
        p = g -> edges[i];
        while (p != NULL) {
            printf(" %d", p -> y);
            p = p->next;
        }
        printf("\n");
    }
}
