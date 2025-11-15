#include<stdio.h>
#define MAX 10
#define INF 9999

int main() {
    int n = 4;
    int cost[MAX][MAX] = {
        {0, 10, 20, 0},
        {10, 0, 5, 0},
        {20, 5, 0, 10},
        {0, 0, 10, 0}
    };
    
    int visited[MAX] = {0};
    int a, b, min, edge = 0, total_cost = 0;

    visited[0] = 1;
    while (edge < n - 1) {
        min = INF;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min && cost[i][j] != 0) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        printf("%d - %d : %d\n", a, b, min);
        total_cost += min;
        edge++;
        visited[b] = 1;
    }
    printf("\nTotal cost = %d\n", total_cost);

    return 0;
}
