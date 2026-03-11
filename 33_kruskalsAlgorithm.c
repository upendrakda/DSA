// Program to implement Kruskal’s Algorithm for Minimum Spanning Tree (MST)
#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Edge {
    int u, v, weight;
};

struct Edge edges[MAX];
int parent[MAX];
int V, E;

// Find function (with path compression)
int find(int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent[i]);
}

// Union function
void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    parent[rootY] = rootX;
}

// Compare function for sorting
int compare(const void* a, const void* b) {
    struct Edge* e1 = (struct Edge*)a;
    struct Edge* e2 = (struct Edge*)b;
    return e1->weight - e2->weight;
}

void kruskal() {
    int count = 0;
    int totalCost = 0;

    // Sort edges by weight
    qsort(edges, E, sizeof(edges[0]), compare);

    // Initialize disjoint sets
    for (int i = 0; i < V; i++)
        parent[i] = i;

    printf("Edges in MST:\n");

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int weight = edges[i].weight;

        if (find(u) != find(v)) {
            printf("%d -- %d == %d\n", u, v, weight);
            totalCost += weight;
            unionSets(u, v);
            count++;
        }
    }

    printf("Total Cost of MST: %d\n", totalCost);
}

int main() {
    system("clear");

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (u v weight):\n");
    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    kruskal();

    return 0;
}
