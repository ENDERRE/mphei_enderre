#ifndef LIB_ST
#define LIB_ST


typedef struct Book {
    char *title;
    char *author;
    int year;
    int pages;
} Book;


typedef struct Node {
    Book data;
    struct Node *prev;
    struct Node *next;
} Node;


typedef struct {
    Node *head;
    Node *tail;
} Library;



#endif
