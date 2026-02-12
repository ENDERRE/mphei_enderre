#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

bool isEmpty(struct Queue* q) {
    if (q->rear == -1) {
        return true;
    }
    return false;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1)
        printf("Queue is full");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(struct Queue* q) {
    int value;
    if (isEmpty(q)) {
        printf("Queue is empty");
        return -1;
    } else {
        value = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
        return value;
    }
}

void breadthFirstSearch(int adjMatrix[MAX_VERTICES][MAX_VERTICES], int startVertex, int numVertices) {
    bool visited[MAX_VERTICES];
    for (int i = 0; i < numVertices; i++) {
        visited[i] = false;
    }

    struct Queue* q = createQueue();
    visited[startVertex] = true;
    enqueue(q, startVertex);

    printf("BFS Traversal: ");
    
    while (!isEmpty(q)) {
        int currentVertex = dequeue(q);
        printf("%d ", currentVertex);

        for (int i = 0; i < numVertices; i++) {
            if (adjMatrix[currentVertex][i] == 1 && !visited[i]) {
                visited[i] = true;
                enqueue(q, i);
            }
        }
    }
}

int main() {
    int adjMatrix[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0},
        {0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0}
    };

    int numVertices = 5;
    int startVertex = 0;
    
    breadthFirstSearch(adjMatrix, startVertex, numVertices);
    
    return 0;
}