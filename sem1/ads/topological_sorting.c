#include<stdio.h>

#define MAX 100

int queue[MAX],inDegree[MAX]={0},topo[MAX],count=0,front = 0, rear = 0;

int main(){
    int n=3;
    int adj[MAX][MAX] = {
        {0,1,1},
        {0,0,1},
        {0,0,0}
    };

    for(int i=0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(adj[i][j] == 1){
                inDegree[j]++;
            }
        }
    }

    for(int i = 0;i<n;i++){
        if(inDegree[i] == 0){
            queue[rear++] = i;
        }
    }

    while(front<rear){
        int vertex = queue[front++];
        topo[count++] = vertex;
        for(int i = 0;i< n;i++){
            if(adj[vertex][i] == 1){
                inDegree[i]--;
                if(inDegree[i] == 0){
                    queue[rear++] = i;
                }
            }
        }
    }

    if(count != n){
        printf("The Graph Have Cycle ! ");
        return 0;
    }

    for(int i=0;i<count;i++){
        printf("%d ",topo[i] );
    }
}

