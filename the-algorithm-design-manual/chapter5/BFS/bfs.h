#define MAXV 1000

typedef enum {FALSE, TRUE} bool;

/* queue */

typedef int item_type;

typedef struct queue {
    item_type item;
    struct queue *next;
} queue;

queue *last_queue(queue *);
queue *penultima_queue(queue *);
void enqueue(queue **, item_type);
item_type dequeue(queue **);
bool empty_queue(queue **);


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
void insert_edge(graph *, int, int, bool);
void print_graph(graph *);


/* bfs */

void initialize_search(graph *);
void process_vertex_late(int);
void process_vertex_early(int);
void process_edge(int, int);
void bfs(graph *, int);
