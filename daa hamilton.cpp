#include <stdio.h>
#include <stdbool.h>

#define V 5 // number of vertices

int graph[V][V] = {
    {0, 1, 1, 1, 0},
    {1, 0, 1, 0, 1},
    {1, 1, 0, 1, 1},
    {1, 0, 1, 0, 1},
    {0, 1, 1, 1, 0}
};

bool is_valid(int v, int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
    return true;
}

bool hamiltonian_circuit(int path[], int pos) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }
    for (int v = 0; v < V; v++) {
        if (is_valid(v, path, pos)) {
            path[pos] = v;
            if (hamiltonian_circuit(path, pos + 1))
                return true;
            path[pos] = -1;
        }
    }
    return false;
}

void print_circuit(int path[]) {
    for (int i = 0; i < V; i++)
        printf("%d ", path[i]);
    printf("%d\n", path[0]);
}

int main() {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;
    path[0] = 0; // start from vertex 0
    if (hamiltonian_circuit(path, 1)) {
        print_circuit(path);
    } else {
        printf("No Hamiltonian circuit exists\n");
    }
    return 0;
}