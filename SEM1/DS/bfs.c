
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

void enqueue(int v) {
	if (rear == MAX - 1)
		return;
	if (front == -1)
		front = 0;
	queue[++rear] = v;
}

int dequeue() {
	if (front == -1 || front > rear)
		return -1;
	return queue[front++];
}

int isEmpty() {
	return (front == -1 || front > rear);
}

void bfs(int adj[MAX][MAX], int n, int start) {
	int i, v;
	for (i = 0; i < n; i++)
		visited[i] = 0;
	enqueue(start);
	visited[start] = 1;
	printf("BFS Traversal: ");
	while (!isEmpty()) {
		v = dequeue();
		printf("%d ", v);
		for (i = 0; i < n; i++) {
			if (adj[v][i] && !visited[i]) {
				enqueue(i);
				visited[i] = 1;
			}
		}
	}
	printf("\n");
}

int main() {
	int n, i, j, start;
	int adj[MAX][MAX];
	printf("Enter number of vertices: ");
	scanf("%d", &n);
	printf("Enter adjacency matrix (row-wise):\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", &adj[i][j]);
		}
	}
	printf("Enter starting vertex (0-based index): ");
	scanf("%d", &start);
	bfs(adj, n, start);
	return 0;
}
