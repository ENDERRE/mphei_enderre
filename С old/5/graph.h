#ifndef LIB_GL
#define LIB_GL


int add_graph(graph** G);
int search_room(graph* G,char* info);
int add_room(graph* G,char* info, enum ro type);
int add_road(graph* G, char* fo, char* to,int si);
int print_graph(graph* G);
void free_graph(graph* G);
int del_room(graph* G,char* name);
int dell_road(graph* G,char* fo,char* to);
void print_matrix(graph* G);
void print_type();
int change_room(graph* G,char* name,enum ro pp);
int print_enter(graph* G);
int print_exit(graph* G);
void printSolution(int* dist, int n,graph* G) ;


void bellmanFord(graph* G, int src, int to) ;
int find_fast(graph* G,char* fir,char* to);
void print_large(int ** dist,char* name,graph *G);
void floydWarshall(graph* G, char* name) ;





struct Queue* createQueue() ;

int isEmpty(struct Queue* q) ;
void enqueue(struct Queue* q, int value,graph* G) ;
int dequeue(struct Queue* q) ;
void breadthFirstSearch(graph* G, int startVertex) ;


#endif