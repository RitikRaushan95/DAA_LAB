#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define V 5

int minKey(vector<int> &key, vector<bool> &mstSet) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

void printMST(vector<int> &parent, vector<vector<int>> &graph) {
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[parent[i]][i] << " \n";
}

void primMST(vector<vector<int>> &graph) {
    vector<int> parent(V);
    vector<int> key(V);
    vector<bool> mstSet(V);

    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST(parent, graph);
}

struct Edge {
    int src, dest, weight;
};

int find(int parent[], int i) {
    return (parent[i] == i) ? i : (parent[i] = find(parent, parent[i]));
}

void unionSet(int parent[], int rank[], int x, int y) {
    int xroot = find(parent, x), yroot = find(parent, y);
    if (rank[xroot] < rank[yroot]) parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot]) parent[yroot] = xroot;
    else { parent[yroot] = xroot; rank[xroot]++; }
}

void kruskalMST(vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) { return a.weight < b.weight; });
    int parent[V], rank[V]; 
    for (int i = 0; i < V; i++) parent[i] = i, rank[i] = 0;
    vector<Edge> mstEdges;
    for (Edge e : edges) {
        int x = find(parent, e.src), y = find(parent, e.dest);
        if (x != y) {
            mstEdges.push_back(e);
            unionSet(parent, rank, x, y);
        }
    }
    cout << "Edge \tWeight\n";
    for (Edge e : mstEdges) 
        cout << e.src << " - " << e.dest << " \t" << e.weight << "\n";
}

int main() {
    vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },
                                  { 2, 0, 3, 8, 5 },
                                  { 0, 3, 0, 0, 7 },
                                  { 6, 8, 0, 0, 9 },
                                  { 0, 5, 7, 9, 0 } };

    vector<Edge> edges = { {0, 1, 2}, {0, 3, 6}, {1, 2, 3}, {1, 3, 8}, {1, 4, 5}, 
                           {2, 4, 7}, {3, 4, 9} };

    cout << "Prim's MST:\n";
    primMST(graph);
    cout << "\nKruskal's MST:\n";
    kruskalMST(edges);

    return 0;
}
