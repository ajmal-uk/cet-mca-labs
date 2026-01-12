#include<stdio.h>
#define MAX 100
#define INF 9999

int visited[MAX] = {0},edge_count=0,total_cost=0,min,u,v;

int main(){
    int n = 4;
    int adj[MAX][MAX] = {
        {0, 10, 20, 0},
        {10, 0, 5, 0},
        {20, 5, 0, 10},
        {0, 0, 10, 0}
    };

    visited[2] = 1;

    while(edge_count<n-1){
        min = INF;
        u = -1;
        v = -1;
        for(int i=0;i<n;i++){
            if(visited[i]){
                for(int j=0;j<n;j++){
                    if(!visited[j] && adj[i][j]!=0 && adj[i][j] < min){
                        min = adj[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        if(v == -1){
            printf("\ngraph is disconnected");
            return 0;
        }

        printf("%d --- %d. :: %d \n",u,v,min);
        visited[v] = 1;
        total_cost+=min;
        edge_count++;
    }
    printf("total cost = %d",total_cost);
    return 0;
}
