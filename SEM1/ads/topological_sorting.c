#include<stdio.h>

#define MAX 100

void topoSorting(int adj[MAX][MAX],int n){
    int inDegree[MAX]={0};
    int queue[MAX];
    int topoSort[MAX];
    int f=0,r=0,count=0;
    
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(adj[i][j]==1){
                inDegree[j]+=1;
            }
        }
    }
    
    
    for(int i= 0;i<n;i++){
        if(inDegree[i]==0){
            queue[r++] = i;
        }
    }
    
    while(f<r){
        int u = queue[f++];
        topoSort[count++] = u;
        for (int v=0;v<n;v++){
            if(adj[u][v] == 1){
                inDegree[v] -=1;
                if(inDegree[v]==0){
                    queue[r++] = v;
                }
            }
        }
    }
    
    if(count!=n){
        printf("Cycle Exist");
    }else{
        printf("topological order is \n");
        for(int i=0;i<n;i++){
            printf("%d ",topoSort[i]);
        }
    }
}

int main() {
    int n=3;
    int adj[MAX][MAX] = {
        {0,1,1},
        {0,0,1},
        {0,0,0}
    };

    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", adj[i][j]);
        printf("\n");
    }

    topoSorting(adj,n);

    return 0;
}
