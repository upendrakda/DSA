// Program to implement Prim’s Algorithm for Minimum Spanning Tree (MST)
#include <stdio.h>
#include <stdlib.h>

#define MAX 20
#define INF 9999

int graph[MAX][MAX], n;

// Function to find minimum key vertex
int minKey(int key[], int visited[]) {
    int min = INF, minIndex;

    for (int v = 0; v < n; v++) {
        if (visited[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void prim() {
    int parent[MAX];
    int key[MAX];
    int visited[MAX];

    for (int i = 0; i < n; i++) {
        key[i] = INF;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int u = minKey(key, visited);
        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && visited[v] == 0 && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printf("Edges in MST:\n");
    int totalCost = 0;

    for (int i = 1; i < n; i++) {
        printf("%d - %d : %d\n", parent[i], i, graph[i][parent[i]]);
        totalCost += graph[i][parent[i]];
    }

    printf("Total Cost of MST: %d\n", totalCost);
}

int main() {
    system("clear");

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    prim();

    return 0;
}
