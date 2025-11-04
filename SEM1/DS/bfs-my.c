#include<stdio.h>
#define MAX 100

int visited[MAX],queue[MAX],front=-1,rear=-1;

void ins(int item){
    if(rear == 99){
        return;
    }
    if(front==-1){
        front+=1;
    }
    queue[++rear] == item;
}

void del(){
    if(rear==-1 || front>rear){
        return -1;
    }
    return queue[front++];
}

int isEmptyQueue(){
    return (front == -1 || front > rear);
}


void bfs(int G[MAX][MAX], int n, int start){
    int i,v;
    for(i=0;i<n;i++){
        visited[i] = 0;
    }
    ins(start);
    visited[start] = 1;
}


void addEdge(int G[MAX][MAX],int u,int v){
    G[u][v] = 1;
}

int main(){
    int G[MAX][MAX] = {0};
}