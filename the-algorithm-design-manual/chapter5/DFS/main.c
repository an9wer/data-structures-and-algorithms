#include <stdio.h>
#include <stdlib.h>
#include "dfs.h"

int main(void)
{
    graph *pg = malloc(sizeof(graph));
    initialize_graph(pg, FALSE);
    read_graph(pg, FALSE);
    initialize_search(pg);
    int start;
    printf("enter started vertex: ");
    scanf("%d", &start);
    dfs(pg, start);
    return 0;
}
