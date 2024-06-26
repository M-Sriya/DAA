#include <stdio.h>
#include <limits.h>

#define V 5 // number of vertices

void primMST(int graph[V][V]) {
    int key[V]; 
    int parent[V];
    int visited[V]; 
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1; 
    for (int count = 0; count < V - 1; count++) {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++) {
            if (visited[v] == 0 && key[v] < min) {
                min = key[v];
                min_index = v;
            }
    }
        visited[min_index] = 1;
        for (int v = 0; v < V; v++) {
            if (graph[min_index][v] && visited[v] == 0 && graph[min_index][v] < key[v]) {
                parent[v] = min_index;
                key[v] = graph[min_index][v];
            }
        }
    }
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]);
    }
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}