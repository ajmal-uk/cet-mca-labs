#include<stdio.h>

#define MAX 100

int stack[MAX];
int visited[MAX] = {0};
int top = -1; 


int pop(){
    if(top == -1){
        return -1;
    }
    return stack[top--];
}
 
void push(int data){
    if(top == MAX-1){
        return;
    }
    stack[++top] = data;
}

int isEmpty(){
    return(top ==-1);
}

void setVisited(int i){
    visited[i] = 1;
}

void dfs(int adj[][MAX], int n, int start){
    push(start);
    printf("DFS Started\n");

    
    while(!isEmpty()){
        int vertex = pop();
        if(!visited[vertex]){
            printf("%d",vertex);
            visited[vertex] = 1;
            for(int i = 0; i< n;i++){
                if(adj[vertex][i] && !visited[i]) push(i);
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
    
    dfs(adj, n , start);
}
