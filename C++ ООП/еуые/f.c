
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "h.h"
#include <ctype.h>
#include <stdint.h>
void initQueue(Queue* q, int size) {
    q->data = NULL;
    if (size!=0) q->data=(int*)malloc(size * sizeof(int));
    q->capacity = size;
    q->front = -1;
    q->rear = -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == q->capacity - 1) {
        printf("==============\n");
        printf("Queue is full!\n");
        printf("==============\n");
        return;
    }
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->data[q->rear] = value;
    printf("==============================\n");
    printf("The element has been added: %d\n", value);
    printf("==============================\n");
}

int dequeue(Queue* q) {
    if (q->front == -1) {
        printf("===============\n");
        printf("Queue is empty!\n");
        printf("===============\n");
        return -1;
    }
    int val = q->data[q->front];
    q->front++;
    if (q->front > q->rear) q->front = q->rear = -1;
    printf("\n");
    printf("===============================\n");
    printf("The item has been extracted: %d\n", val);
    printf("===============================\n");
    return val;
}

void showQueue(Queue* q) {
    if (q->front == -1) {
        printf("===============\n");
        printf("Queue is empty!\n");
        printf("===============\n");
        return;
    }
    printf("================\n");
    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf(" %d", q->data[i]);
    }
    printf("\n================\n");
}

void freeQueue(Queue* q) {
    free(q->data);
}

int serializeQueue(Queue* q, char* filename) {


    FILE* file = fopen(filename, "rb");
    if (!file) return -1;

    fread(q, sizeof(Queue), 1, file);
    printf("%d",q->capacity);
    q->data=malloc(sizeof(int)*q->capacity);
    for (int i=0;i<q->capacity;i++){
        fread((&q->data[i]), sizeof(int), 1, file);
    }
    
    fclose(file);
    return 0;
}

int deserializeQueue(Queue* q,char* filename) {

    FILE* file=NULL;
    file=fopen(filename,"wb");

    if (file == NULL) {
        printf("gg");
        return 0;
    }

    fwrite(q, sizeof(Queue), 1, file);
    for (int i=0;i<q->capacity;i++){
        fwrite((&q->data[i]), sizeof(int), 1, file);
    }
    
    fclose(file);
    printf("fff");
    return 0;
}