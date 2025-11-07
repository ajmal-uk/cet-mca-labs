#include <stdio.h>
#include <stdlib.h>

#define MAX 100

void topologicalSort(int n, int adj[MAX][MAX]) {
    int inDegree[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    int topoOrder[MAX];
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1) {
                inDegree[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0)
            queue[rear++] = i;
    }

    while (front < rear) {
        int u = queue[front++];
        topoOrder[count++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                inDegree[v]--;
                if (inDegree[v] == 0) {
                    queue[rear++] = v;
                }
            }
        }
    }

    if (count != n) {
        printf("\nGraph has a cycle! Topological sorting not possible.\n");
        return;
    }

    printf("\nTopological Order: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", topoOrder[i]);
    }
    printf("\n");
}

int main() {
    int n=6;
    int adj[MAX][MAX] = {0};

    adj[5][0] = 1;
    adj[5][2] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    topologicalSort(n, adj);

    return 0;
}
