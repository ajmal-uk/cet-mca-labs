#include <stdio.h>

#define MAX 100
#define INF 9999

int main() {
    int visited[MAX] = {0};
    int edge_count = 0, total_cost = 0, a=-1, b=-1 , min,n=4;
    visited[0]=1;
    int adj[MAX][MAX] = {
        {0, 10, 20, 0},
        {10, 0, 5, 0},
        {20, 5, 0, 10},
        {0, 0, 10, 0}
    };
    while(edge_count < n-1){
        min = INF;
        a = -1;
        b=-1;
        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(!visited[j] && adj[i][j]<min && adj[i][j]!=0){
                        min = adj[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }
        
        if (min == INF || a == -1 || b == -1) {
            printf("Graph is disconnected — no more reachable edges.\n");
            break;
        }
        
        printf("%d - %d : %d\n", a, b, min);
        total_cost += min;
        visited[b] = 1;
        edge_count++;
    }
    printf("\nTotal cost = %d\n", total_cost);
    return 0;
}
