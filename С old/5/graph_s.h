#ifndef LIB_S
#define LIB_S


#define INT_MAX       2147483647
struct Queue {
    int *items;
    int front;
    int rear;
};
enum ro
{
    enter,
    cor,
    ex

};


typedef struct room {
    char* name;
    enum ro type;
} room;

typedef struct graph {
    room** enter;
    int **matrix;
    int size;
} graph;
#endif