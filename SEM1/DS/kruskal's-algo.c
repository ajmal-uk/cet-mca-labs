#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int u, v, w;
} Edge;

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void unionSets(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(Edge edges[], int n, int e) {
    int i, j;
    Edge temp;
    int totalCost = 0;

    for (i = 0; i < e - 1; i++) {
        for (j = 0; j < e - i - 1; j++) {
            if (edges[j].w > edges[j + 1].w) {
                temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++)
        parent[i] = i;

    printf("\nEdges in the Minimum Spanning Tree:\n");

    int edgeCount = 0;
    for (i = 0; i < e && edgeCount < n - 1; i++) {
        int a = find(edges[i].u);
        int b = find(edges[i].v);

        if (a != b) {
            printf("%d - %d \tCost: %d\n", edges[i].u, edges[i].v, edges[i].w);
            totalCost += edges[i].w;
            unionSets(a, b);
            edgeCount++;
        }
    }

    printf("\nMinimum Cost of Spanning Tree = %d\n", totalCost);
}

int main() {
    int n = 6;
    int e = 9;

    Edge edges[] = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {1, 0, 4},
        {2, 3, 3},
        {2, 5, 2},
        {2, 4, 4},
        {3, 4, 3},
        {5, 4, 3}
    };

    kruskal(edges, n, e);
    return 0;
}
