
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;
int visited[MAX];

void push(int v) {
	if (top >= MAX - 1)
		return; 
	stack[++top] = v;
}

int pop() {
	if (top == -1)
		return -1;
	return stack[top--];
}

int isEmpty() {
	return (top == -1);
}


void dfs(int adj[MAX][MAX], int n, int start) {
	int i, v;

	for (i = 0; i < n; i++)
		visited[i] = 0;

	push(start);
	printf("DFS Traversal: ");

	while (!isEmpty()) {
		v = pop();
		if (v == -1) break; 
		if (!visited[v]) {
			printf("%d ", v);
			visited[v] = 1;
			for (i = n - 1; i >= 0; i--) {
				if (adj[v][i] && !visited[i])
					push(i);
			}
		}
	}
	printf("\n");
}

int main() {
	int n, i, j, start;
	int adj[MAX][MAX];

	printf("Enter number of vertices: ");
	if (scanf("%d", &n) != 1) return 1;
	if (n <= 0 || n > MAX) {
		printf("Invalid number of vertices (1..%d)\n", MAX);
		return 1;
	}

	printf("Enter adjacency matrix (row-wise):\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (scanf("%d", &adj[i][j]) != 1) return 1;
		}
	}

	printf("Enter starting vertex (0-based index): ");
	if (scanf("%d", &start) != 1) return 1;
	if (start < 0 || start >= n) {
		printf("Start vertex out of range\n");
		return 1;
	}

	dfs(adj, n, start);
	return 0;
}




