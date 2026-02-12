#ifndef LIB_ST
#define LIB_ST

#define DEFINE_LINKED_LIST(Node,int)\
    typedef struct Node{\
        int release;\
        int info;\
        struct Node *next;\
    }Node;
DEFINE_LINKED_LIST(node,int);

#define DEFINE_LINKED_KEY(Keyspace,int)\
    typedef struct Keyspace{\
        int key;\
        struct Keyspace* next;\
        node* list;\
    }Keyspace;
DEFINE_LINKED_KEY(keyspace,int);

#define DEFINE_LINKED_TABLE(tab,int)\
typedef struct {\
    int size;\
    int n;\
    keyspace** ks;\
}tab;
DEFINE_LINKED_TABLE(table,int);

#define DEFINE_ENUM_SE(SE)\
enum SE\
{\
    none ,\
    error,\
    pr_key,\
    pr_ver,\
    del_key,\
    del_ver\
};
DEFINE_ENUM_SE(se)



#endif
