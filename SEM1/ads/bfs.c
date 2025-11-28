#include<stdio.h>

#define MAX 100

int visited[MAX] = {0};
int queue[MAX];
int front=0, rear=0;

void bfs(int n,int adj[MAX][MAX],int start){
    queue[rear++] = start;
    visited[start]=1;
    while(front < rear){
        int u = queue[front++];
        printf("%d ",u);
        for(int v=0;v<n;v++){
            if(adj[u][v]==1 && !visited[v]){
                queue[rear++] = v;
                visited[v] =1;
            }
        }
    }
}

int main(){
    int n = 5;
    int adj[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };
    int start = 0;
    bfs(n,adj,start);
    return 0;
}
