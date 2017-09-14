#define MAXV 1000
#define MAXINT 10000

typedef enum {FALSE, TRUE} bool;

/* adjacency lists */

typedef struct edgenode {
    int y;                  // adjacency info
    int weight;             // edge weight, if any
    struct edgenode *next;  // next edge in list
} edgenode;

typedef struct {
    edgenode *edges[MAXV+1];    // adjacency info
    int degree[MAXV+1];         // outdegree of each vertex
    int nvertices;              // number of vertices in graph
    int nedges;                 // number of edges in graph
    bool directed;              // is the graph directed
} graph;

void initialize_graph(graph *, bool);
void read_graph(graph *, bool);
void insert_edge(graph *, int, int, int, bool);
void print_graph(graph *);
