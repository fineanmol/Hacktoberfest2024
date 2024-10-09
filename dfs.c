#include <stdio.h>
#include <stdlib.h>
#define MAX 100
void DFS(int);
void addEdge(int, int);

int adjMatrix[MAX][MAX];
int visited[MAX];
int n; 
int main() {
    int i, j;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            adjMatrix[i][j] = 0;
        }
        visited[i] = 0;
    }
    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }

    printf("DFS traversal starting from vertex 0:\n");
    DFS(0);
    return 0;
}
void DFS(int vertex) {
    int i;
    visited[vertex] = 1;
    printf("%d ", vertex);
    for (i = 0; i < n; i++) {
        if (adjMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
