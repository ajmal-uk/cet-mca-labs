#include<stdio.h>

#define MAX 100

int visited[MAX] = {0};
int stack[MAX];
int top=-1;

int isEmpty(){
    if(top == -1){
        return 1;
    }
    return 0;
}

void dfs(int n,int adj[MAX][MAX],int start){
    stack[++top] = start;
    
    while(!isEmpty()){
        int u = stack[top--];
        if(!visited[u]){
            printf("%d",u);
            visited[u] = 1;
            for(int v=0;v<n;v++){
                if(adj[u][v]==1 && !visited[v]){
                    stack[++top] = v;
                }
            }
        }
        
    }
}


void main(){
    int n = 5;
    int adj[MAX][MAX] = {
        {0,1,1,0,0},
        {1,0,1,1,0},
        {1,1,0,0,1},
        {0,1,0,0,1},
        {0,0,1,1,0}
    };
    int start = 0;
    
    dfs(n,adj,start);
}


