#ifndef LIB_ST
#define LIB_ST


enum se
{
    none ,
    error,
    del_no,
    del_er,
    print_el,
    no_el,
    print_t

};
typedef struct Node {
    int key;
    int size;
    int *value;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Tree {
    Node* root;
    Node* fir;
} Tree;


#endif