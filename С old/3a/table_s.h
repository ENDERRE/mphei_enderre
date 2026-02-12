#ifndef LIB_ST
#define LIB_ST
enum op
{
    none ,
    error,
    pr_t,
    pr_g 

};
typedef struct {
    int key;
    char* info;
}keyspace;

typedef struct {
    int size;
    int n;
    keyspace* ks;
}table;


#endif