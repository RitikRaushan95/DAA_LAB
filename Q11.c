#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

typedef struct {
    int src, dest, weight;
} Edge;

void bellmanFord(int V, int E, Edge edges[], int start) {
    int *dist = (int *)malloc(V * sizeof(int));
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[start] = 0;

    for (int i = 0; i < V - 1; i++)
        for (int j = 0; j < E; j++) {
            int u = edges[j].src, v = edges[j].dest, w = edges[j].weight;
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }

    for (int j = 0; j < E; j++) {
        int u = edges[j].src, v = edges[j].dest, w = edges[j].weight;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative weight cycle detected.\n");
            free(dist);
            return;
        }
    }

    printf("Bellman-Ford:\n");
    for (int i = 0; i < V; i++)
        printf("0 -> %d: %s\n", i, dist[i] == INF ? "INF" : (char[]) { '0' + dist[i], '\0' });

    free(dist);
}

void dijkstra(int V, int **adj, int start) {
    int *dist = (int *)malloc(V * sizeof(int));
    int *visited = (int *)calloc(V, sizeof(int));

    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[start] = 0;

    for (int i = 0; i < V - 1; i++) {
        int min = INF, u = -1;
        for (int v = 0; v < V; v++)
            if (!visited[v] && dist[v] < min) min = dist[v], u = v;

        visited[u] = 1;

        for (int v = 0; v < V; v++)
            if (adj[u][v] && !visited[v] && dist[u] != INF && dist[u] + adj[u][v] < dist[v])
                dist[v] = dist[u] + adj[u][v];
    }

    printf("Dijkstra:\n");
    for (int i = 0; i < V; i++)
        printf("0 -> %d: %s\n", i, dist[i] == INF ? "INF" : (char[]) { '0' + dist[i], '\0' });

    free(dist);
    free(visited);
}

int main() {
    int V, E, start;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &V, &E);

    Edge *edges = (Edge *)malloc(E * sizeof(Edge));
    int **adj = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        adj[i] = (int *)calloc(V, sizeof(int));
    }

    printf("Enter edges (src dest weight):\n");
    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i] = (Edge) {u, v, w};
        adj[u][v] = w;
    }

    printf("Enter start vertex: ");
    scanf("%d", &start);

    bellmanFord(V, E, edges, start);
    printf("\n");
    dijkstra(V, adj, start);

    free(edges);
    for (int i = 0; i < V; i++) free(adj[i]);
    free(adj);

    return 0;
}
