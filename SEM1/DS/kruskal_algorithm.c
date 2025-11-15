#include<stdio.h>
#define MAX 10
#define INF 9999

int parent[MAX];

int find(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void unionSet(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

int main() {
    int n = 4;
    int e = 5;
    int cost[MAX][MAX] = {
        {0, 10, 20, 0},
        {10, 0, 5, 0},
        {20, 5, 0, 10},
        {0, 0, 10, 0}
    };
    
    int weight[MAX][3];
    int costMST = 0, edgesAccepted = 0;

    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (cost[i][j] != 0) {
                weight[k][0] = i;
                weight[k][1] = j;
                weight[k][2] = cost[i][j];
                k++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    while (edgesAccepted < n - 1) {
        int min = INF, a, b, u = -1;

        for (int i = 0; i < e; i++) {
            if (weight[i][2] < min) {
                min = weight[i][2];
                a = weight[i][0];
                b = weight[i][1];
                u = i;
            }
        }

        if (find(a) != find(b)) {
            printf("%d - %d : %d\n", a, b, min);
            costMST += min;
            edgesAccepted++;
            unionSet(a, b);
        }

        weight[u][2] = INF;
    }

    printf("Minimum cost = %d\n", costMST);
    return 0;
}
