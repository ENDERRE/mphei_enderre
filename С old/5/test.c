#include <stdio.h>
#include <limits.h>

#define V 6 // Количество вершин графа

typedef struct {
    int src;
    int dest;
    int weight;
} Edge;

void printSolution(int dist[], int n) {
    printf("Вершина \t Расстояние от источника\n");
    for (int i = 0; i < V; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}

void bellmanFord(int graph[V][V], int src) {
    int dist[V];
  
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] && dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    for (int u = 0; u < V; u++) {
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                printf("Граф содержит отрицательные циклы\n");
                return;
            }
        }
    }
    
    printSolution(dist, V);
}

int main() {
    int graph[V][V] = { {0, 1, 4, 0, 0, 0},
                        {0, 0, 3, 2, 2, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 1, 5, 0, 0, 1},
                        {0, 0, 0, 3, 0, 0},
                        {0, 0, 0, 0, 1, 0} };
  
    bellmanFord(graph, 0);
  
    return 0;
}