#ifndef LIB_ST
#define LIB_ST


typedef struct node{
    int release;
    int info;
    struct node *next;
    
}node;
typedef struct keyspace{
    int key;
    struct keyspace* next;
    node* list;
}keyspace;

typedef struct {
    int size;
    int n;
    keyspace** ks;
}table;

enum se
{
    none ,
    error,
    pr_key,
    pr_ver,
    del_key,
    del_ver

};


#endif