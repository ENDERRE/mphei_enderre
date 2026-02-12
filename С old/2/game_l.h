#ifndef LIB_M
#define LIB_M

typedef struct {
    int row;
    int col;
}pos;
 typedef struct {
    int g;
    pos *vec;
    int top;
}vectr;

typedef struct el{
    pos p;
    struct el* next;
}el;
typedef struct {
    el* head;
}stack;
typedef struct {
    int **fir;
    int si;
    pos empt;
}puzzle;




#endif