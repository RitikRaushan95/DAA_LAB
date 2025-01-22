#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100

typedef struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(Graph* graph, int u, int v) {
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
}

void BFT(Graph* graph, int start) {
    bool visited[MAX_VERTICES] = {false};
    int queue[MAX_VERTICES], front = 0, rear = 0;

    visited[start] = true;
    queue[rear++] = start;

    printf("Breadth-First Traversal starting from vertex %d: ", start);
    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjMatrix[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}


void DFT(Graph* graph, int start) {
    bool visited[MAX_VERTICES] = {false};
    int stack[MAX_VERTICES], top = -1;

    stack[++top] = start;

    printf("Depth-First Traversal starting from vertex %d: ", start);
    while (top != -1) {
        int current = stack[top--];

        if (!visited[current]) {
            visited[current] = true;
            printf("%d ", current);
        }

        for (int i = graph->vertices - 1; i >= 0; i--) {
            if (graph->adjMatrix[current][i] == 1 && !visited[i]) {
                stack[++top] = i;
            }
        }
    }
    printf("\n");
}

int main() {
    Graph graph;
    initGraph(&graph, 6);

    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 1, 4);
    addEdge(&graph, 2, 4);
    addEdge(&graph, 3, 5);
    addEdge(&graph, 4, 5);

    
    BFT(&graph, 0); 
    DFT(&graph, 0); 


    return 0;
}
