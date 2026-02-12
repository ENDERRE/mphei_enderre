#ifndef QUEUE_LIB_H
#define QUEUE_LIB_H

#include <stdio.h>
#include <stdlib.h>
#ifdef _DEBUG
# define DEBUG_MODE
# define PRINT_DEBUG(msg) printf("[DEBUG] Line:%d (%s): %s\n\n", __LINE__, __func__, #msg);
#else
# define RELEASE_MODE
# define PRINT_DEBUG(msg)
#endif
#define DEFINE_LINKED_LIST(int) \
    typedef struct {\
        \
            int* data; \
            int capacity; \
            int front; \
            int rear; \
    } Queue;

DEFINE_LINKED_LIST(int);

void initQueue(Queue* q, int size);

void enqueue(Queue* q, int value);

int dequeue(Queue* q);

void showQueue(Queue* q);

void freeQueue(Queue* q);

int serializeQueue(Queue* q, char* filename);

int deserializeQueue(Queue* q, char* filename);

#endif